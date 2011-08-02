/***********************************************************************
 ** Copyright (C) 2010 Aras Balali Moghaddam.  All rights reserved.
 **
 ** This file is part of the Movid Software.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appearing in the file
 ** LICENSE included in the packaging of this file.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** Contact info@movid.org if any conditions of this licensing are
 ** not clear to you.
 **
 **********************************************************************/


#include "moMinEigenValModule.h"
#include "../moLog.h"
#include "cv.h"
#include <highgui.h>

MODULE_DECLARE(MinEigenVal, "not native", "Calculates minimum eigen value for a region around each pixel and store it in that pixel");

moMinEigenValModule::moMinEigenValModule() : moImageFilterModule(){
	MODULE_INIT();
	//scale for visibility of output image
    this->properties["scale"] = new moProperty(5);
    this->properties["scale"]->setMin(1);
    this->properties["scale"]->setMax(255);
	
	this->properties["block_size"] = new moProperty(16);
	this->properties["aperture_size"] = new moProperty(3);

	this->setInputType(0, "IplImage8");
    this->setOutputType(0, "IplImage8");
}

moMinEigenValModule::~moMinEigenValModule() {
}

void moMinEigenValModule::applyFilter(IplImage *src) {
	cvConvertImage(src, this->converted);
	cvCornerMinEigenVal(this->converted, this->eigenImage, this->property("block_size").asInteger(), this->property("aperture_size").asInteger());
	cvConvertScale(this->eigenImage, this->output_buffer, this->property("scale").asInteger(), 0);
}

void moMinEigenValModule::allocateBuffers() {
    IplImage* src = static_cast<IplImage*>(this->input->getData());
    if ( src == NULL )
	    return;
    // Converted version of the input img
    this->converted = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    // The img that will contain the actual distances
    this->eigenImage = cvCreateImage(cvGetSize(src), IPL_DEPTH_32F, 1);
    this->output_buffer = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    LOG(MO_DEBUG, "allocated output buffer for minEigenVal module.");
}
