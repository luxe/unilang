var gulp = require('gulp');
var gulputil = require('gulp-util');
var sass = require('gulp-sass')
var prefix = require('gulp-autoprefixer');

gulp.task('default', function () {
    gulp.src('./scss/*.scss')
    	.pipe(sass())
        .pipe(gulp.dest('./css'))

	// gulp.src('./css/*.css')
	//   .pipe(prefix({ cascade: true }))
	//   .pipe(gulp.dest('./dist/'));
});