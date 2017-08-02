# Main
As we revisit our Main content template we currently have an identical copy of our Pattern Lab Main layout using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/layout` folder we can modify our template to include the Main layout from Pattern Lab by following these steps:


- Replace the markup in `region--content.html.twig` with the following:


    {% extends '@layouts/main/main.twig' %}
    
    {% block main %}
      {{ content }}
    {% endblock %}


> **Extends**
> 
> Above we are extending the Main layout from Pattern Lab by referencing the namespace and path to the `main.twig` file.
> 
> When we use a Twig extends it allows us to inherit the markup of our component similar to using an `include` while allowing us to replace content in the component using Twig blocks.  However unlike a Twig include a Twig extends does not allow us to pass variables to template.


- Save the Twig template

When using the extends technique we need to ensure that our layout is configured with identical Twig blocks.

## Step Two: Modify layout

If we navigate to the `/web/themes/pattern-lab/source/_patterns/02-layouts/main` folder we can modify our component by following these steps:


- Replace the markup in `main.twig` with the following:


    <main id="main" class="main" role="main" tabindex="-1">
      {% block main %}
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
      {% endblock %}
    </main>


> Above we have added our Twig block to match that of our Main content template.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Main content layout now matches our Main layout in Pattern Lab.

