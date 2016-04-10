; diszkontkereso make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++

projects[ctools][version] = "1.9"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.9"
projects[date][subdir] = "contrib"

projects[profiler_builder][version] = "1.2"
projects[profiler_builder][subdir] = "contrib"

projects[ds][version] = "2.13"
projects[ds][subdir] = "contrib"

projects[diszkont][version] = "1.0"
projects[diszkont][subdir] = "contrib"

projects[features][version] = "2.8"
projects[features][subdir] = "contrib"

projects[feeds][version] = "2.0-beta2"
projects[feeds][subdir] = "contrib"

projects[computed_field][version] = "1.1"
projects[computed_field][subdir] = "contrib"

projects[computed_field_tools][version] = "1.1"
projects[computed_field_tools][subdir] = "contrib"

projects[references][version] = "2.1"
projects[references][subdir] = "contrib"

projects[term_reference_tree][version] = "1.10"
projects[term_reference_tree][subdir] = "contrib"

projects[url][version] = "1.0"
projects[url][subdir] = "contrib"

projects[hybridauth][version] = "2.15"
projects[hybridauth][subdir] = "contrib"

projects[masonry][version] = "3.0-beta1"
projects[masonry][subdir] = "contrib"

projects[masonry_views][version] = "3.0"
projects[masonry_views][subdir] = "contrib"

projects[node_export][version] = "3.1"
projects[node_export][subdir] = "contrib"

projects[colorbox][version] = "2.10"
projects[colorbox][subdir] = "contrib"

projects[disablepwstrength][version] = "1.1"
projects[disablepwstrength][subdir] = "contrib"

projects[email_registration][version] = "1.3"
projects[email_registration][subdir] = "contrib"

projects[entity][version] = "1.7"
projects[entity][subdir] = "contrib"

projects[job_scheduler][version] = "2.0-alpha3"
projects[job_scheduler][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[logintoboggan][version] = "1.5"
projects[logintoboggan][subdir] = "contrib"

projects[pathauto][version] = "1.3"
projects[pathauto][subdir] = "contrib"

projects[persistent_login][version] = "1.0-rc1"
projects[persistent_login][subdir] = "contrib"

projects[purl][version] = "1.x-dev"
projects[purl][subdir] = "contrib"

projects[r4032login][version] = "1.8"
projects[r4032login][subdir] = "contrib"

projects[remember_me][version] = "1.0"
projects[remember_me][subdir] = "contrib"

projects[shs][version] = "1.6"
projects[shs][subdir] = "contrib"

projects[stickynav][version] = "1.0"
projects[stickynav][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][subdir] = "contrib"

projects[transliteration][version] = "3.2"
projects[transliteration][subdir] = "contrib"

projects[print][version] = "2.0"
projects[print][subdir] = "contrib"

projects[rules][version] = "2.9"
projects[rules][subdir] = "contrib"

projects[search_autocomplete][version] = "4.7"
projects[search_autocomplete][subdir] = "contrib"

projects[taxonomy_csv][version] = "5.10"
projects[taxonomy_csv][subdir] = "contrib"

projects[uuid][version] = "1.0-beta1"
projects[uuid][subdir] = "contrib"

projects[jquery_update][version] = "2.7"
projects[jquery_update][subdir] = "contrib"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = "contrib"

projects[wysiwyg_mediaembed][version] = "1.0"
projects[wysiwyg_mediaembed][subdir] = "contrib"

projects[better_exposed_filters][version] = "3.2"
projects[better_exposed_filters][subdir] = "contrib"

projects[exposed_filter_data][version] = "1.2"
projects[exposed_filter_data][subdir] = "contrib"

projects[mefibs][version] = "1.0-alpha1"
projects[mefibs][subdir] = "contrib"

projects[views][version] = "3.13"
projects[views][subdir] = "contrib"

projects[views_infinite_scroll][version] = "1.1"
projects[views_infinite_scroll][subdir] = "contrib"

projects[views_php][version] = "1.0-alpha3"
projects[views_php][subdir] = "contrib"

projects[views_selective_filters][version] = "1.5"
projects[views_selective_filters][subdir] = "contrib"

projects[views_modes][version] = "1.x-dev"
projects[views_modes][subdir] = "contrib"

; +++++ Themes +++++

; bootstrap
projects[bootstrap][type] = "theme"
projects[bootstrap][version] = "3.5"
projects[bootstrap][subdir] = "contrib"

; +++++ Libraries +++++

; ColorBox
libraries[colorbox][directory_name] = "colorbox"
libraries[colorbox][type] = "library"
libraries[colorbox][destination] = "libraries"
libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/archive/master.zip"

; jQuery Masonry
libraries[masonry][directory_name] = "masonry"
libraries[masonry][type] = "library"
libraries[masonry][destination] = "libraries"
libraries[masonry][download][type] = "get"
libraries[masonry][download][url] = "http://masonry.desandro.com/jquery.masonry.min.js"

; Plupload
libraries[plupload][directory_name] = "plupload"
libraries[plupload][type] = "library"
libraries[plupload][destination] = "libraries"
libraries[plupload][patch][] = "http://drupal.org/files/plupload-1_5_6-rm_examples-1903850-5.patch"
libraries[plupload][download][type] = "file"
libraries[plupload][download][url] = "http://plupload.com/downloads/plupload_1_5_6.zip"

; CKEditor
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][type] = "library"
libraries[ckeditor][destination] = "libraries"
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.6.1/ckeditor_3.6.6.1.tar.gz"

