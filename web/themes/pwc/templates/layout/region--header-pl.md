# Header
As we revisit our Header template we currently have an identical copy of our Pattern Lab Header layout using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/layout` folder we can modify our template to include the Header layout from Pattern Lab by following these steps:


- Replace the markup in `region--header.html.twig` with the following:


    {% extends '@layouts/header/header.twig' %}
    
    {% block header %}
      {{ content }}
    {% endblock %}


> **Extends**
> 
> Above we are extending the Header layout from Pattern Lab by referencing the namespace and path to the `header.twig` file.
> 
> When we use a Twig extends it allows us to inherit the markup of our component similar to using an `include` while allowing us to replace content in the component using Twig blocks.  However unlike a Twig include a Twig extends does not allow us to pass variables to template.


- Save the Twig template

When using the extends technique we need to ensure that our layout is configured with identical Twig blocks.

## Step Two: Modify layout

If we navigate to the `/web/themes/pattern-lab/source/_patterns/02-layouts/header` folder we can modify our component by following these steps:


- Replace the markup in `header.twig` with the following:


    <header class="header" role="banner">
      <div class="header__grid l-constrain">
        {% block header %}
          {% include "components-site-name" %}
          {% include "components-nav-main" %}
        {% endblock %}
      </div>
    </header>


> Above we have added our Twig block to match that of our Header template.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Header layout now matches our Header layout in Pattern Lab.

