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
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component
## Step Two - Using Data attributes

Currently our component displays static values.  Lets replace them using Data attributes and Twig variables.


- Create a a new file called `hero.yml`
- Add the following content, keeping in mind that YAML requires specific formatting:

```
    hero_image: "../../../../images/hero-whale.jpg"
    hero_title: "Safe Waters, Safe Whales"
    hero_text: "The Pacific Whale Conservancy helps protect the habitats of whales through education, activism, and outreach so that whales can be free, the way nature intended."
    has_button: true
    button_url: "#"
    button_label: "Learn More"
```

- Save the file
- Edit `hero.twig` and replace the static values with Twig variables for each attribute.

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

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-hero to view our component

Our Hero component is now complete.
