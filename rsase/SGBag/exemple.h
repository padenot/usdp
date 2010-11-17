/**
 * @file exemple.h
 * @author M. Coctail (mr.coctail@insa-lyon.fr)
 */

#ifndef EXEMPLE_H
#define EXEMPLE_H

#include "Bar.h"

// PAS DE USING NAMESPACE ICI

/**
 * Class description
 */
class Foo : public Bar
{
public :
	/** Do something.
	 * Do something with the following requirements....
	 * @return An error code
	 * @param[in] arg1 This argument ...
	 * @param[out] arg2 This argument ...
	 * @param[in,out] arg3 This argument ...
	 */
	int function (int arg1, int** arg2, int& arg3);

protected :
	/// @todo This is a TODO

private :
	int _member; /// Member description
};

#endif // EXEMPLE_H
