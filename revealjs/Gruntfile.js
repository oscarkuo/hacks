module.exports = function(grunt) {
  grunt.initConfig({
    copy: {
      main: {
        expand: true,
        cwd: 'src/copy/',
        src: '**',
        dest: 'out/'
      }
    },

    sass: {
      dist: {
        files: { 
          'out/css/theme/black.css': 'src/sass/theme/black.scss',
          'out/css/reveal.css': 'src/sass/reveal.scss',
          'out/css/blocky.css': 'src/sass/blocky.scss',
        }
      }
    },

    jade: {
      options: {
        pretty: true
      },
      main: {
        files: {
          'out/aws2015.html': 'src/jade/aws2015.jade'
        }
      }
    },
  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-jade');
  grunt.loadNpmTasks('grunt-contrib-copy');

  grunt.registerTask('default', ['copy', 'sass', 'jade']);
};
