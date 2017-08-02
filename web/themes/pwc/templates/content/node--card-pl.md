# Card
As we revisit our Card template we currently have an identical copy of our Pattern Lab Card component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/content` folder we can modify our template to include the Card component from Pattern Lab by following these steps:


- Replace the markup in `node--card.html.twig` with the following:


    {% set img_url = node.field_featured_image.entity.field_image.entity.uri.value|image_style('card') %}
    {% set img_alt = content.field_featured_image|field_target_entity.field_image.alt %}
    
    {% include "@components/card/card.twig"
      with {
        "card_url": url,
        "card_image": {
          "src": img_url,
          "alt": img_alt
        },
        "card_date": content.field_published|field_value,
        "card_heading": content.title|field_value,
        "card_teaser": content.field_summary|field_value
      }
    %}


> **Includes**
> 
> Above we are including the Card component from Pattern Lab by referencing the namespace and path to the `card.twig` file.  We are then using the `with` keyword to pass our Twig variables to the component.  This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Card display now matches our Card component in Pattern Lab.

