# Hero
As we revisit our Hero template we currently have an identical copy of our Pattern Lab Hero component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/paragraph` folder we can modify our template to include the Hero component from Pattern Lab by following these steps:


- Replace the markup in `paragraph--hero.html.twig` with the following:


    {% embed "@components/hero/hero.twig"
      with {
        "hero_image": content.field_background_image|field_value,
        "hero_title": content.field_heading|field_value,
        "hero_text": content.field_subheading|field_value,
        "has_button": true,
      }
    %}
    
      {% block button %}
        {% include "@components/button/button.twig"
          with {
            "button_modifier": "button--outline",
            "button_url": content.field_button_url|field_value,
            "button_label": content.field_button_label|field_value
          }
        %}
      {% endblock %}
    
    {% endembed %}


> **Embed**
> 
> Above we are embeding the Hero component from Pattern Lab by referencing the namespace and path to the `hero.twig` file.  We are then using the `with` keyword to pass our Twig variables to the component.
> 
> When we use a Twig embed it allows us to inherit the markup of our component similar to using an `include` while allowing us to replace content in the component using Twig blocks.  We are using this to include our button component within our Hero component.
> 
> This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template

When using the embed technique we need to ensure that our component is configured with identical Twig blocks.

## Step Two: Modify component

If we navigate to the `/web/themes/pattern-lab/source/_patterns/01-components/hero` folder we can modify our component by following these steps:


- Replace the markup in `hero.twig` with the following:


    <div class="hero" style="background-image: url({{ hero_image }});">
      <div class="l-constrain">
        <div class="hero__content">
          <h1 class="hero__title">{{ hero_title }}</h1>
          <div class="hero__text">{{ hero_text|raw }}</div>
          {% if has_button %}
            <div class="hero__call-to-action">
              {% block button %}
                {% include "components-button"
                  with {
                    button_modifier: button_modifier,
                    button_label: button_label,
                    button_url: button_url
                  }
                %}
              {% endblock %}
            </div>
          {% endif %}
        </div>
      </div>
    </div>


> Above we have added our Twig block to match that of our Hero template.  We have also added a conditional check to see if Drupal wants to add the button block using Pattern Lab specific data with the `has_button` key/value.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Hero paragraph now matches our Hero component in Pattern Lab.

