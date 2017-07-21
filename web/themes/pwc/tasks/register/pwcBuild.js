module.exports = function (grunt) {
  grunt.registerTask('pwcBuild', [
    'pwcBuildStyles',
    'pwcBuildImages',
    'pwcBuildPatternlab'
  ]);
};
