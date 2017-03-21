/*
* Access to iPAQ Asset Information store in flash
*
* Copyright 2001,2002,2003 Compaq Computer Corporation.
*
* Use consistent with the GNU GPL is permitted,
* provided that this copyright notice is
* preserved in its entirety in all copies and derived works.
*
* COMPAQ COMPUTER CORPORATION MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
* AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
* FITNESS FOR ANY PARTICULAR PURPOSE.
*
* Author:  Andrew Christian
*          <Andrew.Christian@compaq.com>
*          October 2001
*
* Restrutured June 2002
*
* Moved into separate modules March 2003
* Jamey Hicks <jamey.hicks@hp.com>
*/

int ipaq_mtd_asset_read( struct h3600_asset *asset );
int ipaq_mtd_asset_init( void );
void ipaq_mtd_asset_cleanup( void );

