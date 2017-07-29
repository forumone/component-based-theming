# Header

## Step One - Building a layout
Creating a layout is actually quite easy.  All that we need is a twig template with the name of our layout and the HTML markup that makes up our component.

- Create a new file called `header.twig`
- Add the following markup:

```
  <header class="header" role="banner">
    <div class="header__grid l-constrain">
      Header components
    </div>
  </header>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-header to view our layout.

## Step Two - Using includes within a layout
If we take another look at our Header layout we will notice that we only have the beginning of a layout but no true content.  We can include the site-name and nav-main to our layout using a Twig `include` to render our components.  Lets remedy that now by making the following change to our Header layout.

- Edit `header.twig` and add the includes for site-name and nav-main:

```
  <header class="header" role="banner">
    <div class="header__grid l-constrain">
      {% include "components-site-name" %}
      {% include "components-nav-main" %}
    </div>
  </header>
```

- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-header to view our layout.

Our Header layout is now complete.
