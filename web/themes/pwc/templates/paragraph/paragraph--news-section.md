# News Section
Drupal 8 can extend the management of content using Entities.  One such type of Entities popular with site builders is the Paragraphs module.  Paragraph types similar to Content types are fieldable but unlike their counterparts, do not have a standalone display.  Instead Paragraphs are referenced from Content types and because of this it makes them complimentary and a great use for components.

Each Paragraph type has a template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the News section using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `paragraph.html.twig`.

### Specificity
Before we go haphazardly overriding the `paragraph.html.twig` we need to keep in mind that all Paragraphs created within Drupal will use this same block regardless of what type of Paragraph we are outputting.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `paragraph--news-section.html.twig` template.  This will ensure that only our News section is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Paragraph template being used by our News section, so our output is `/web/themes/pwc/templates/paragraph`.

## Step Three: Create Paragraph template
If we navigate to the `/web/themes/pwc/templates/paragraph` folder we can begin creating a new template.  Start by following these steps:

- Duplicate `paragraph.html.twig`
- Rename to `paragraph--news-section.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/main/` folder and copy the `section--alt` markup containing the Updates and New Species content.
- Replace the markup in `paragraph--news-section.html.twig` with the following:

```
  <section class="section section--alt">
    <div class="l-constrain">
      <div class="l-grid l-grid--50">
        <div class="section__col">
          <h2 class="section__title">Updates</h2>
          {% include "components-listing" %}
          {% include "components-listing" %}
          {% include "components-listing" %}
          {% include "components-listing" %}
        </div>
        <div class="section__col">
          <h2 class="section__title">New Species</h2>
          {% include "components-teaser" %}
          {% include "components-teaser" %}
          {% include "components-teaser" %}
          {% include "components-teaser" %}
        </div>
      </div>
    </div>
  </section>
```

> **Replacing Twig include**
>
> Next we will want to replace the `include` statements for `components-listing` and `components-teaser` with the fields from Drupal that contains the real content.

- Navigate to http://pwc.dd:8083/admin/structure/paragraphs_type/news_section/fields to see a list of the fields and their respective machine names.
- Replace the `include` statements so our Twig template looks like the following:

```
  <section class="section section--alt">
    <div class="l-constrain">
      <div class="l-grid l-grid--50">
        <div class="section__col">
          <h2 class="section__title">Updates</h2>
          {{ content.field_view_one }}
        </div>
        <div class="section__col">
          <h2 class="section__title">New Species</h2>
          {{ content.field_view_two }}
        </div>
      </div>
    </div>
  </section>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our News Section section almost matches our News section in Pattern Lab.  However, currently each field is printing out the machine_name of each view.

## Step Four: Embedding Views
One of the contributed modules that we have installed called Twig Tweak allows us to embed various content including blocks, menus, nodes, entities and even views.  The Twig function that we can use to embed views uses `{{ drupal_view() }}` and takes multiple arguments.  Including the name of the view.

- Open `paragraph--news-section.html.twig` and modify the markup as follows:

```
  <section class="section section--alt">
    <div class="l-constrain">
      <div class="l-grid l-grid--50">
        <div class="section__col">
          <h2 class="section__title">Updates</h2>
          {{ drupal_view(content.field_view_one.0['#plain_text']) }}
        </div>
        <div class="section__col">
          <h2 class="section__title">New Species</h2>
          {{ drupal_view(content.field_view_two.0['#plain_text']) }}
        </div>
      </div>
    </div>
  </section>
```

> So you may be asking why we are not simply printing out the fields value to pass the name to embed it on the page.  The challenge here is that `{{ drupal_view() }}` expects the view name to be a string value and one way to retrieve it is by using dot syntax notation to grab the plain text value of the field.
>
> Since we know that each View name only contains a single value we can reference the first instance and then the `#plain_text` value from that.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our News Section section matches our News section in Pattern Lab.
