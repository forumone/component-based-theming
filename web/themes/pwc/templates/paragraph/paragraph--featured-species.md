# Featured Species
Drupal 8 can extend the management of content using Entities.  One such type of Entities popular with site builders is the Paragraphs module.  Paragraph types similar to Content types are fieldable but unlike their counterparts, do not have a standalone display.  Instead Paragraphs are referenced from Content types and because of this it makes them complimentary and a great use for components.

Each Paragraph type has a template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Feature section using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `paragraph.html.twig`.

### Specificity
Before we go haphazardly overriding the `paragraph.html.twig` we need to keep in mind that all Paragraphs created within Drupal will use this same block regardless of what type of Paragraph we are outputting.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `paragraph--featured-species.html.twig`template.  This will ensure that only our Featured section is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Paragraph template being used by our Featured section, so our output is `/web/themes/pwc/templates/paragraph`.

## Step Three: Create Paragraph template
If we navigate to the `/web/themes/pwc/templates/paragraph` folder we can begin creating a new template.  Start by following these steps:

- Duplicate `paragraph.html.twig`
- Rename to `paragraph--featured-species.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/main/` folder and copy the section markup containing the Featured content.
- Replace the markup in `paragraph--featured-species.html.twig` with the following:

```
  <section class="section">
    <div class="l-constrain">
      <div class="section__inner">
        <h2 class="section__title">Featured</h2>
        <div class="l-grid l-grid--cards">
          {% include "components-card" %}
          {% include "components-card" %}
          {% include "components-card" %}
          {% include "components-card" %}
        </div>
      </div>
    </div>
  </section>
```

> **Replacing Twig include**
>
> Next we will want to replace the `include` statements for `components-card` with the fields from Drupal that contains the real content.

- Navigate to http://pwc.dd:8083/admin/structure/paragraphs_type/featured_species/fields to see a list of the fields and their respective machine names.
- Replace the `include` statements and content so our Twig template looks like the following:

```
  <section class="section">
    <div class="l-constrain">
      <div class="section__inner">
        <h2 class="section__title">{{ content.field_heading|field_value }}</h2>
        <div class="l-grid l-grid--cards">
          {{ content.field_species|field_value }}
        </div>
      </div>
    </div>
  </section>
```

> **Twig Field Value**
>
> Again we are taking advantage of the Twig Field Value module that adds a new Twig filter `field_value` that returns a string value from each field.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Featured section now matches our Featured section in the Main layout in Pattern Lab.
