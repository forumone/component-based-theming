module.exports = function (grunt) {
  grunt.registerTask('pwcBuildStyles', [
    'sass_globbing:pwc',
    'sass:pwc',
    'postcss:pwc'
  ]);
};
