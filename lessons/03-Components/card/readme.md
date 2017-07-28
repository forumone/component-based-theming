# Card

## Step One - Building a component

Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.


- Create a new file called `card.twig`
- Add the following markup:


    <div class="card">
        <div class="card__media">
          <a href="#"><img src="/sites/pwc.dd/files/media/image/killer-whales.jpg" alt="Killer whale"></a>
        </div>
        <div class="card__body">
          <div class="card__date">July 20, 2017</div>
          <h3 class="card__heading"><a href="#">Killer whale</a></h3>
          <div class="card__teaser">The killer whale or orca is a toothed whale belonging to the oceanic dolphin family, of which it is the largest member.</div>
        </div>
      </div>


- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-card to view our component
## Step Two - Using Data attributes

Currently our component displays static values.  Lets replace them using Data attributes and Twig variables.


- Create a a new file called `card.yml`
- Add the following content, keeping in mind that YAML requires specific formatting:


    card_url: "#"
    card_image:
      src: "/sites/pwc.dd/files/media/image/killer-whales.jpg"
      alt: "Killer whale"
    card_date: "July 20, 2017"
    card_heading: "Killer whale"
    card_teaser: "The killer whale or orca is a toothed whale belonging to the oceanic dolphin family, of which it is the largest member."
    


- Save the file
- Edit `card.twig` and replace the static values with Twig variables for each attribute.


    <div class="card">
      <div class="card__media">
        <a href="{{ card_url }}"><img src="{{ card_image.src }}" alt="{{ card_image.alt }}"></a>
      </div>
      <div class="card__body">
        <div class="card__date">{{ card_date }}</div>
        <h3 class="card__heading"><a href="{{ card_url }}">{{ card_heading }}</a></h3>
        <div class="card__teaser">{{ card_teaser }}</div>
      </div>
    </div>
    


- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-card to view our component.

Our card component is now complete.

