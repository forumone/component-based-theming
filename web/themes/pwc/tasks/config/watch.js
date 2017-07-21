module.exports = function (grunt) {
  grunt.config.merge({
    watch: {
      pwc: {
        files: ['<%= pkg.themePath %>/sass/**/*.scss','<%= pkg.themePath %>/pattern-lab/source/_patterns/**/*.scss'],
        tasks: ['pwcBuildStyles'],
      },
      patternlab: {
        files: ['<%= pkg.themePath %>/pattern-lab/source/**/*.twig','<%= pkg.themePath %>/pattern-lab/source/**/*.json','<%= pkg.themePath %>/pattern-lab/source/**/*.yaml'],
        tasks: ['shell:patternlab'],
        options: {
          livereload: true
        }
      },
      svgs: {
        files: ['<%= pkg.themePath %>/images/bg/*.svg'],
        tasks: ['pwcBuildImages', 'pwcBuildStyles'],
      },
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-simple-watch');
}
