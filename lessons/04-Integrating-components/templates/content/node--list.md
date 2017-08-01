# Listing
Drupal 8 can extend the display of content using Display modes or View modes.  This feature allows us to manage field per display mode for each Content type that we work with. The trick is to be semantic as possible when naming Display modes.  In the case of our design we already identified a Teaser component which we can then map to a List display.

Each Display mode has a Twig template associated with it, along with the ability to have per Content type display modes.  As such we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Listing content using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `node.html.twig`.

### Specificity
Before we go haphazardly overriding the `node.html.twig` we need to keep in mind that all Nodes created within Drupal will use this same node template regardless of what type of Node we are outputting.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `node--list.html.twig`template.  This will ensure that only our Listing is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Node template being used by our Listing, so our output is `/web/themes/pwc/templates/content`.

## Step Three: Create Node template
If we navigate to the `/web/themes/pwc/templates/content` folder we can begin creating a new template.  Start by following these steps:

- Duplicate `node.html.twig`
- Rename to `node--list.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/listing/` folder and copy the markup.
- Replace the markup in `node--list.html.twig` with the following:

```
  <article class="listing" role="article">
    <div class="listing__date">{{ listing_date }}</div>
    <h2 class="listing__heading"><a href="{{ listing_url }}">{{ listing_heading }}</a></h2>
  </article>
```

> **Converting Twig variables**
>
> Next we need to replace Pattern Labs Twig variables with Drupal’s Twig variables for our List Display mode.  This process relies on knowing what the machine name for each field is called.

- Navigate to http://pwc.dd:8083/admin/structure/types/manage/species/fields to see a list of the fields and their respective machine names.
- Replace each Twig variable with `{{ content.field_name }}` replacing field_name with the machine name so that are markup looks like the following:

```
  <article class="listing" role="article">
    <div class="listing__date">{{ content.field_published|field_value }}</div>
    <h2 class="listing__heading"><a href="{{ url }}">{{ content.title|field_value }}</a></h2>
  </article>
```

> **Twig Field Value**
>
> One of the challenges of working with the content variable in Drupal is always knowing exactly what the field will return.  To help with this we are using a contributed module called Twig Field Value that adds a new Twig filter `field_value` that returns a string value from the field.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our List display now matches our Listing component in Pattern Lab.
