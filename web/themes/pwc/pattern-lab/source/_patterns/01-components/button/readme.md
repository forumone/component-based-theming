# Button

## Step One - Building a component

Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.


- Create a new file called `button.twig`
- Add the following markup:


```html
    <a href="#" class="button">Learn More</a>
```

- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-button to view our component
## Step Two - Using Data attributes

Currently our component displays static values for the URL and Label of our anchor element.  However, we can make this component a little more dynamic by using Data attributes and Twig variables to replace our static values with dynamic values.


- Create a a new file called `button.yml`
- Add the following content, keeping in mind that YAML requires specific formatting:


    button_url: "#"
    button_label "Learn More"


- Save the file
- Edit `button.twig` and replace the static values with Twig variables for each attribute.


    <a href="{{ button_url }}" class="button">{{ button_label }}</a>


- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-button to view our component.


## Step Three - Using Includes to create a variant

Creating a variant of a component comes in handy when we need an identical version of a component with only slight modifications.  For example, the button within the Hero component is much like the normal button, except it has an outline.

While we could simply duplicate our button component markup in a separate component file,  we should follow the DRY principle (Don’t Repeat Yourself) which will make the code base simpler and future maintenance easier.

Twig allows us to reference one template within another and return the rendered content of that file using what is called an `include`.  Lets try this by following these steps.


- Create a new Twig file within our button folder called `button-outline.twig` and include our original `button.twig` template within it by adding the following:


    {% include "components-button %}


> Note that an include within Pattern Lab follows the root folder and component file name that is being referenced.  In the case above, the button.twig file located in the 01-components/button folder can be referenced by stating components-button.  There is no need to include the absolute or relative path, subfolders or file extension.


- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-button-outline to view our button-outline component.


## Step Four: Using data attributes with Includes

Our **button-outline** component now has the same markup as our original **button** component.  In order to alter it, we will need a way to pass it variables.

The `include` statement we used above also allow us to pass variables to the original button component that will override the data attributes currently being displayed by using the `with` attribute like such.


- Edit `button-outline.twig` and add the following markup:


    {% include "components-button
      with {
        button_label: "Learn More",
        button_url: "#"
      }
    %}


- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-button-outline to view our button-outline component.

Our button-outline component should still look the same, however if you change the value being passed to `button_label`, saved the file and refreshed the browser we would see that the data attributes our being replaced now.


## Step Five: Adding a class modifier

We are almost done with our button-outline component.  The only missing step is the ability to add a variant class to the origin button component that will add some additional CSS when passed to it.

Begin with adding a new Data attribute to the `button.yml` file.


- Edit `button.yml` and add the following Data attribute:


    button_modifier: ""
    button_url: "#"
    button_label "Learn More"


- Save the file

Next we will need to add a Twig variable for our new data attribute to `button.twig`


- Edit `button.twig` and add the following Twig variable:


    <a href="{{ button_url }}" class="button {{ button_modifier }}">{{ button_label }}</a>


- Save the file

Finally, all we need to do is update our button-outline.yml file and pass the css variant within our include.


- Edit `button-outline.twig` and add the following markup:


    {% include "components-button
      with {
        button_modifier: "button--outline",
        button_label: "Learn More",
        button_url: "#"
      }
    %}


- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-button-outline to view our button-outline component.

Our button-outline component now has the correct styling being picked up and if we compare the 2 button components we will see that each one is displaying independently yet they use the same markup.
