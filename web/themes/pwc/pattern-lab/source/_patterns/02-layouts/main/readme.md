# Main

## Step One - Building a layout
Creating a layout is actually quite easy.  All that we need is a twig template with the name of our layout and the HTML markup that makes up our component.

- Create a new file called `main.twig`
- Add the following markup:

```
  <main id="main" class="main" role="main" tabindex="-1">
    Hero component

    <section class="section">
      <div class="l-constrain">
        <div class="section__inner">
          <h2 class="section__title">Featured</h2>
          <div class="l-grid l-grid--cards">
            Card component
          </div>
        </div>
      </div>
    </section>

    <section class="section section--alt">
      <div class="l-constrain">
        <div class="l-grid l-grid--50">
          <div class="section__col">
            <h2 class="section__title">Updates</h2>
            Listing component
          </div>
          <div class="section__col">
            <h2 class="section__title">New Species</h2>
            Teaser component
          </div>
        </div>
      </div>
    </section>

  </main>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-main to view our layout.

## Step Two - Using includes within a layout
If we take another look at our Main layout we will notice that we only have the beginning of a layout but no true content.  We can include the hero, card, listing and teaser to our layout using a Twig `include` to render our components.  Lets remedy that now by making the following change to our Main layout.

- Edit `main.twig` and add the includes for hero, card, listing and teaser:

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

- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-main to view our layout.

Our Main layout is now complete.
