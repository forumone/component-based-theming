# Teaser
Drupal 8 can extend the display of content using Display modes or View modes.  This feature allows us to manage field per display mode for each Content type that we work with. The trick is to be semantic as possible when naming Display modes.  In the case of our design we already identified a Teaser component which we can then map to a Teaser display.

Each Display mode has a Twig template associated with it, along with the ability to have per Content type display modes.  As such we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Teaser content using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `node.html.twig`.

### Specificity
Before we go haphazardly overriding the `node.html.twig` we need to keep in mind that all Nodes created within Drupal will use this same node template regardless of what type of Node we are outputting.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `node--teaser.html.twig`template.  This will ensure that only our Teaser is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Node template being used by our Teaser, so our output is `/web/themes/pwc/templates/content`.

## Step Three: Create Node template
If we navigate to the `/web/themes/pwc/templates/content` folder we can begin creating a new template.  Start by following these steps:

- Duplicate `node.html.twig`
- Rename to `node--teaser.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/teaser/` folder and copy the markup.
- Replace the markup in `node--teaser.html.twig` with the following:

```
  <article class="teaser" role="article">
    <img class="teaser__img" src="{{ teaser_image.src }}" alt="{{ teaser_image.alt }}">
    <div class="teaser__body">
      <div class="teaser__date">{{ teaser_date }}</div>
      <h2 class="teaser__heading"><a href="{{ teaser_url }}">{{ teaser_heading }}</a></h2>
    </div>
  </article>
```

> **Converting Twig variables**
>
> Next we need to replace Pattern Labs Twig variables with Drupal’s Twig variables for our Teaser Display mode.  This process relies on knowing what the machine name for each field is called.

- Navigate to http://pwc.dd:8083/admin/structure/types/manage/species/fields to see a list of the fields and their respective machine names.
- Replace each Twig variable with `{{ content.field_name }}` replacing field_name with the machine name so that are markup looks like the following:

```
  <article class="teaser" role="article">
    <img class="teaser__img" src="" alt="">
    <div class="teaser__body">
      <div class="teaser__date">{{ content.field_published|field_value }}</div>
      <h2 class="teaser__heading"><a href="{{ url }}">{{ content.title|field_value }}</a></h2>
    </div>
  </article>
```

> **Twig Field Value**
>
> One of the challenges of working with the content variable in Drupal is always knowing exactly what the field will return.  To help with this we are using a contributed module called Twig Field Value that adds a new Twig filter `field_value` that returns a string value from the field.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

## Step Four: Entity Reference fields
So you may have noticed that we have not yet printed the content for the **src** and **alt** attributes of our teaser image field.  The reasoning is that we need to be able to retrieve the src and alt attribute values from an **Entity Reference** field to the Image Media type which has a field called `field_image`.  I know, sounds confusing, but we will look at a few techniques that make this a little easier to understand.

We can use a few different techniques to introspect Drupal variables, the easiest way is by using Twig’s `{{ dump() }}` function.  Before we do this though, be warned, that simply dumping the **content** variable from Drupal will eat up a lot of memory and in most cases you will end up with a WSOD (White Screen of Death).

Instead we will print out `content.field_featured_image` using a the `keys` filter to get access to the values we can print.

- Edit  `node--teaser.html.twig` and add the following to the top of our template:

```
  <pre>{{ dump(content.field_featured_image|keys) }}</pre>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

We are now seeing a bit more information that our field contains and we can print each of these values out.  However we are still not seeing the entity that contains the field we need.

Anytime we are within a Node template, we also have access to the Node object itself and print out any values it may contain.  Since we know we need to access the Entity attached to our Featured Image field we can replace the current dump statement with the following:

```
  <pre>{{ dump(node.field_featured_image.entity|keys) }}</pre>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

We are now seeing the `field_image` value and are learning how to introspect the node object that allows for us to drill deeper into content.  Too jump ahead a little, let’s replace the current dump statement with the following:

```
  <pre>{{ dump(node.field_featured_image.entity.field_image.entity.uri.value) }}</pre>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

Now we have the string value for our Featured Image field returned from the Image field being referenced.  Yet, the value is returning the Public path to the image and not the relative path to the image style derivative.  This is where the use of another contributed module called Twig Tweak becomes useful.

## Step Five: Twig Tweak
The Twig Tweak module should be part of any Drupal 8 themer’s arsenal of tools.  This one contributed module allows us to embed blocks, views, node, entities and much more within Twig templates.  The other function that it provides is being able to take the Public path of an image and pass an Image style to it which converts the string to a relative path to the image derivative.

- Edit  `node--teaser.html.twig` and replace the dump statement with the following:

```
  {% set img_url = node.field_featured_image.entity.field_image.entity.uri.value|image_style('card') %}

  <article class="teaser" role="article">
    <img class="teaser__img" src="{{ img_url }}" alt="">
    <div class="teaser__body">
      <div class="teaser__date">{{ content.field_published|field_value }}</div>
      <h2 class="teaser__heading"><a href="{{ url }}">{{ content.title|field_value }}</a></h2>
    </div>
  </article>
```

> We are using Twig to create a variable titled `img_url` and setting the value to the image style derivative using the `image_style('teaser')` function.  Then we are taking the newly created variable and printing it as our images src attribute value.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

The last thing left to do is to also retrieve the Image fields alt attribute from the referenced Entity.  We can achieve this by using the Twig Field Value function `field_target_entity` to reference the Entity and then traverse to the alt value.  To complete the Theming of our Teaser Display we can add the following:

```
  {% set img_alt = content.field_featured_image|field_target_entity.field_image.alt %}

  <article class="teaser" role="article">
    <img class="teaser__img" src="{{ img_url }}" alt="{{ img_alt }}">
    <div class="teaser__body">
      <div class="teaser__date">{{ content.field_published|field_value }}</div>
      <h2 class="teaser__heading"><a href="{{ url }}">{{ content.title|field_value }}</a></h2>
    </div>
  </article>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Teaser display now matches our Teaser component in Pattern Lab.
