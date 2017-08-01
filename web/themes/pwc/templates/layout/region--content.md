# Main
Drupal 8 manages the output of content blocks using **Regions** defined in a theme.   Each region has a Twig template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Content region using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `region.html.twig`.

### Specificity
Before we go haphazardly overriding the `region.html.twig` we need to keep in mind that all Regions created within Drupal will use this same block regardless if we are outputting a Header region, a Footer region, etc.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `region--content.html.twig` template.  This will ensure that only our Content region is output using this template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a Region template being used by our Content, so our output is `/web/themes/pwc/templates/region`.

## Step Three: Create Region template
If we navigate to the `/web/themes/pwc/templates/region` folder we can begin creating a new Region template.  Start by following these steps:

- Duplicate `region.html.twig`
- Rename to `region--content.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/02-layouts/main/` folder and copy the markup.
- Replace the markup in `region--content.html.twig` with the following:

```
  <main id="main" class="main" role="main" tabindex="-1">
    {% include "components-hero" %}

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

  </main>
```

Next we will want to replace the `include` statements with `{{ content }}`.  This will output any blocks that have been placed in the Content region.  Our template should now look like the following:

```
    <main id="main" class="main" role="main" tabindex="-1">
      {{ content }}
    </main>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Content region now matches our Main layout in Pattern Lab.
