# Footer
As we revisit our Footer template we currently have an identical copy of our Pattern Lab Footer layout using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/layout` folder we can modify our template to include the Footer layout from Pattern Lab by following these steps:


- Replace the markup in `region--footer.html.twig` with the following:


    {% extends '@layouts/footer/footer.twig' %}
    
    {% block top %}
      {{ drupal_block('pwc_site_branding_footer') }}
    {% endblock %}
    
    {% block bottom %}
      {{ drupal_block('pwc_footer') }}
    {% endblock %}


> **Extends**
> 
> Above we are extending the Footer layout from Pattern Lab by referencing the namespace and path to the `footer.twig` file.
> 
> When we use a Twig extends it allows us to inherit the markup of our component similar to using an `include` while allowing us to replace content in the component using Twig blocks.  However unlike a Twig include a Twig extends does not allow us to pass variables to template.


- Save the Twig template

When using the extends technique we need to ensure that our layout is configured with identical Twig blocks.

## Step Two: Modify layout

If we navigate to the `/web/themes/pattern-lab/source/_patterns/02-layouts/footer` folder we can modify our component by following these steps:


- Replace the markup in `footer.twig` with the following:


    <footer class="footer" role="contentinfo">
      <div class="footer__top">
        <div class="l-constrain">
          {% block top %}
            {% include "components-site-name" %}
          {% endblock %}
         </div>
      </div>
      <div class="footer__bottom">
        <div class="l-constrain">
          {% block bottom %}
            {% include "components-nav-footer" %}
          {% endblock %}
        </div>
      </div>
    </footer>


> Above we have added our Twig blocks to match that of our Footer template.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Footer layout now matches our Footer layout in Pattern Lab.

