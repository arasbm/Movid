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


#ifndef MO_MINEIGENVAL_MODULE_H
#define MO_MINEIGENVAL_MODULE_H

#include "moImageFilterModule.h"

class moMinEigenValModule : public moImageFilterModule{
public:
	moMinEigenValModule();
	virtual ~moMinEigenValModule();
	
protected:
	IplImage* converted;
	IplImage* eigenImage;
	void applyFilter(IplImage *);
	void allocateBuffers();
	MODULE_INTERNALS();
};

#endif

