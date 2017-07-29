# Hero

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `hero.twig`
- Add the following markup:

```
  <div class="hero" style="background-image: url('../../../../images/hero-whale.jpg');">
    <div class="l-constrain">
      <div class="hero__content">
        <h1 class="hero__title">Safe Waters, Safe Whales</h1>
        <div class="hero__text">The Pacific Whale Conservancy helps protect the habitats of whales through education, activism, and outreach so that whales can be free, the way nature intended.</div>
        <div class="hero__call-to-action">
          <a href="#" class="button button--outline">Learn More</a>
        </div>
      </div>
    </div>
  </div>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `hero.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  hero_image: "../../../../images/hero-whale.jpg"
  hero_title: "Safe Waters, Safe Whales"
  hero_text: "The Pacific Whale Conservancy helps protect the habitats of whales through education, activism, and outreach so that whales can be free, the way nature intended."
  has_button: true
  button_url: "#"
  button_label: "Learn More"
```

- Save the file
- Edit `hero.twig` and replace the static values with Twig variables for each key.

```
  <div class="hero" style="background-image: url({{ hero_image }});">
    <div class="l-constrain">
      <div class="hero__content">
        <h1 class="hero__title">{{ hero_title }}</h1>
        <div class="hero__text">{{ hero_text|raw }}</div>
        {% if button_url %}
          <div class="hero__call-to-action">
            <a href="{{ button_url }}" class="button button--outline">{{ button_label }}</a>
          </div>
        {% endif %}
      </div>
    </div>
  </div>
```

> A couple of things to mention regarding our Hero component markup is the introduction of Twig filters and Twig Control structures

**Twig filters** allow for variables to be modified using a pipe symbol (|) followed by the name of the filer.  An example of a Twig filter that we are using above is `raw` which returns the literal value of a string.  This is handy when a key may contain markup.  The `raw` filter will ensure that markup within a string is interpreted and not printed.

**Twig Control structures** allow for controlling the flow of variables.  This can include conditionals such as `if/elseif/else` , `for` loops and Twig blocks.  An example of a Twig control structure is our use of checking if the `button_url` key is being passed to our Hero component.  This allows for us to show or hide the button on the Hero and is handy to modify the markup of a component based on pattern-specific data.

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component.

## Step Three - Using includes within a component
If we take another look at our Hero component we will notice that our Hero’s button markup is identical to the button component that we had created earlier.  However we are not taking advantage of using a Twig `include` to render our button.  Lets remedy that now by making the following change to our Hero component.

- Edit `hero.twig` and replace the button markup:

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
                button_modifier: "button--outline",
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

- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component.

## Step Four - Adding key/value to Pattern specific data
One last thing to clean up on our Hero component now that we are including the base template for our button is to add a key/value pair for the `button_modifier` to our Hero component’s pattern specific data.

- Edit `hero.yml`
- Add the following key and value pair, keeping in mind that YAML requires specific formatting:

```
  hero_image: "../../../../images/hero-whale.jpg"
  hero_title: "Safe Waters, Safe Whales"
  hero_text: "The Pacific Whale Conservancy helps protect the habitats of whales through education, activism, and outreach so that whales can be free, the way nature intended."
  has_button: true
  button_modifier: "button--outline"
  button_url: "#"
  button_label: "Learn More"
```

- Save the file
- Edit `hero.twig` and replace the `button_modifer` string value with our new key:

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

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component.

Our Hero component is now complete.
