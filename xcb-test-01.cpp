
#include <cstdlib>
#include <cstdio>
#include <xcb/xcb.h>

void printScreenStruct ( xcb_screen_t * screen, int index ) {
	if ( screen ) {
		printf( "\n" );
		printf( "Details for screen at index %d:\n", index );
		//printf( "  root:                     %ld\n", screen->root );
		//printf( "  default_colormap:         %ld\n", screen->default_colormap );
		printf( "  white_pixel:              %u\n", screen->white_pixel );
		printf( "  black_pixel:              %u\n", screen->black_pixel );
		printf( "  current_input_masks:      %u\n", screen->current_input_masks );
		printf( "  width_in_pixels:          %d\n", screen->width_in_pixels );
		printf( "  height_in_pixels:         %d\n", screen->height_in_pixels );
		printf( "  width_in_millimeters:     %d\n", screen->width_in_millimeters );
		printf( "  height_in_millimeters:    %d\n", screen->height_in_millimeters );
		printf( "  min_installed_maps:       %d\n", screen->min_installed_maps );
		printf( "  max_installed_maps:       %d\n", screen->max_installed_maps );
		//printf( "  root_visual:              %ld\n", screen->root_visual );
		printf( "  backing_stores:           %hd\n", screen->backing_stores );
		printf( "  save_unders:              %hd\n", screen->save_unders );
		printf( "  root_depth:               %hd\n", screen->root_depth );
		printf( "  allowed_depths_len:       %hd\n", screen->allowed_depths_len );
		printf( "\n" );
	} else {
		printf ( "Screen at index %d is NULL.", index );
	}
	printf( "\n" );
}

int main () {

	/* print out the display environment variable */

	char * display = getenv( "DISPLAY" );
	printf( "DISPLAY: %s\n", ( display ) ? display : "" );

	/* connect to the X server */

	int screenNumber = -1;
	xcb_connection_t * xcbConnection = xcb_connect( NULL, &screenNumber );

	if ( xcbConnection ) {
		printf( "Screen Number: %d\n", screenNumber );
		
		/* set up the connection and get a screen iterator */

		const xcb_setup_t * xcbSetup = xcb_get_setup( xcbConnection );
		xcb_screen_iterator_t screenIterator = xcb_setup_roots_iterator( xcbSetup );

		/* iterate to the screen we got in xcb_connect */

		for ( int i = 0; i < screenNumber; i++ ) {
			printScreenStruct( screenIterator.data, i );
			xcb_screen_next( &screenIterator );
		}

		printScreenStruct( screenIterator.data, screenNumber );

		xcb_disconnect( xcbConnection );
	} else {
		printf( "Failed to connect to X server; xcb_connect returned NULL." );
	}

	return EXIT_SUCCESS;
}

