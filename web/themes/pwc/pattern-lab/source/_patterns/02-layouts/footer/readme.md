# Footer

## Step One - Building a layout
Creating a layout is actually quite easy.  All that we need is a twig template with the name of our layout and the HTML markup that makes up our component.

- Create a new file called `footer.twig`
- Add the following markup:

```
  <footer class="footer" role="contentinfo">
    <div class="footer__top">
      <div class="l-constrain">
         Footer component
       </div>
    </div>
    <div class="footer__bottom">
      <div class="l-constrain">
        Footer component
      </div>
    </div>
  </footer>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-footer to view our layout.

## Step Two - Using includes within a layout
If we take another look at our Footer layout we will notice that we only have the beginning of a layout but no true content.  We can include the site-name and nav-footer to our layout using a Twig `include` to render our components.  Lets remedy that now by making the following change to our Footer layout.

- Edit `footer.twig` and add the includes for site-name and nav-footer:

```
  <footer class="footer" role="contentinfo">
    <div class="footer__top">
      <div class="l-constrain">
         {% include "components-site-name" %}
       </div>
    </div>
    <div class="footer__bottom">
      <div class="l-constrain">
        {% include "components-nav-footer" %}
      </div>
    </div>
  </footer>
```

- Save the file
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=layouts-footer to view our layout.

Our Footer layout is now complete.
