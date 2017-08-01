# Hero
Drupal 8 can extend the management of content using Entities.  One such type of Entities popular with site builders is the Paragraphs module.  Paragraph types similar to Content types are fieldable but unlike their counterparts, do not have a standalone display.  Instead Paragraphs are referenced from Content types and because of this it makes them complimentary and a great use for components.

Each Paragraph type has a template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Main menu using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `paragraph.html.twig`.

### Specificity
Before we go haphazardly overriding the `paragraph.html.twig` we need to keep in mind that all Paragraphs created within Drupal will use this same block regardless of what type of Paragraph we are outputting.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `paragraph--hero.html.twig` template.  This will ensure that only our Hero is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Paragraph template being used by our Hero, so our output is `/web/themes/pwc/templates/paragraph`

## Step Three: Create Paragraph template
If we navigate to the `/web/themes/pwc/templates/paragraph` folder we can begin creating a new template.  Start by following these steps:

- Duplicate `paragraph.html.twig`
- Rename to `paragraph--hero.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/hero/` folder and copy the markup.
- Replace the markup in `paragraph--hero.html.twig` with the following:

```
  <div class="hero" style="background-image: url({{ hero_image }});">
    <div class="l-constrain">
      <div class="hero__content">
        <h1 class="hero__title">{{ hero_title }}</h1>
        <div class="hero__text">{{ hero_text|raw }}</div>
        {% if button_url %}
          <div class="hero__call-to-action">
            {% include "components-button"
              with {
                button_modifier: button_modifier,
                button_label: button_label,
                button_url: button_url
              }
            %}
          </div>
        {% endif %}
      </div>
    </div>
  </div>
```

> **Replacing Twig include**
>
> Next we will want to replace the `include` statement for `components-button` with the actual markup that generates our button.

- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/button/` folder and copy the markup from `button.twig`.
- Replace the `include` statement so our Twig template looks like the following:

```
  <div class="hero" style="background-image: url({{ hero_image }});">
    <div class="l-constrain">
      <div class="hero__content">
        <h1 class="hero__title">{{ hero_title }}</h1>
        <div class="hero__text">{{ hero_text|raw }}</div>
        {% if button_url %}
          <div class="hero__call-to-action">
            <a href="{{ button_url }}" class="button {{ button_modifier }}">{{ button_label }}</a>
          </div>
        {% endif %}
      </div>
    </div>
  </div>
```

> **Converting Twig variables**
>
> Next we need to replace Pattern Labs Twig variables with Drupal’s Twig variables for our Hero Paragraph type.  This process relies on knowing what the machine name for each field is called.

- Navigate to http://pwc.dd:8083/admin/structure/paragraphs_type/hero/fields to see a list of the fields and their respective machine names.
- Replace each Twig variable with `{{ content.field_name }}` replacing field_name with the machine name so that are markup looks like the following:

```
  <div class="hero" style="background-image: url({{ content.field_background_image|field_value }});">
    <div class="l-constrain">
      <div class="hero__content">
        <h1 class="hero__title">{{ content.field_heading|field_value }}</h1>
        <div class="hero__text">{{ content.field_subheading|field_value }}</div>
        <div class="hero__call-to-action">
          <a class="button button--outline" href="{{ content.field_button_url|field_value }}">{{ content.field_button_label|field_value }}</a>
        </div>
      </div>
    </div>
  </div>
```    

> **Twig Field Value**
>
> One of the challenges of working with the content variable in Drupal is always knowing exactly what the field will return.  To help with this we are using a contributed module called Twig Field Value that adds a new Twig filter `field_value` that returns a string value from the field.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Hero is starting to take shape.  However we are not quite done with theming our Hero quite yet.

## Step Four: Managing Media
Since we are following best practices for managing media, we have the Media module installed and configured.  The challenge is that currently the Hero paragraph type’s Background Image field is referencing the Image Media type’s Hero display mode.  This display is set to output our Hero image as an actual picture element.  As well as this display has it’s own Twig template printing the content.

Since our design dictates that our Hero uses a background image, we need to change the Hero display of our Image Media type to account for this using the new **URL to image** field formatter.

- Navigate to http://pwc.dd:8083/admin/structure/media/manage/image/display
- Select the Hero display mode
- Change the Image field format from Image to URL to image
- Select the field formatted and change the Image style from None (original image) to Hero (2000x600) Desktop
- Select the Update button
- Select the Save button

Navigate back to the homepage and refresh the browser.  We will see that our Hero’s background image has disappeared and we are seeing some HTML fragments being printed on the page.  If we inspect the Hero component using Google Chrome’s Developer Tools we will notice that the Image Media type also has a Twig template it is outputting the background image from.

If we navigate to `/web/themes/pwc/templates/` folder we can create a new media folder and the required media template by following these steps:

- Create a new folder called `media`
- Using the File Name Suggestions create a new Twig template called `media--image--hero.html.twig`
- Add the following markup:

```
  {{ content.field_image|field_value }}
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Hero is almost complete.  Actually it is 100% complete.  The one issue with using background images in Drupal when Twig Debug is enabled is that HTML comments are printed causing the background-image to contain extra content.  If we quickly disable Twig Debug and clear the cache we will see that our Hero now matches our Hero component.

Since we rely on having Twig Debug enabled, don’t forget to re-enable it.
