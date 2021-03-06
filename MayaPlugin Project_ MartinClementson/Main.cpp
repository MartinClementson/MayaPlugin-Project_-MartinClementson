
#include "MayaIncludes.h"

#include <maya/MFnPlugin.h>
#include "CallbackHandler.h"
#define UNICODE 1


//circular_buffer<char>* localBuffer;
CallbackHandler* callbackHandler = nullptr;

EXPORT MStatus initializePlugin(MObject obj) {
	std::cout.rdbuf(std::cerr.rdbuf());


	MStatus result = MS::kSuccess;

	// Set plugin registration info: Author, plugin-version and Maya version needed.
	MFnPlugin plugin(obj, "Martin_Clementson", "1.0", "2016", &result);

	if (MFAIL(result))
	{
		CHECK_MSTATUS(result);
		return result;
	}

	//localBuffer		= new circular_buffer<char>;
	

	callbackHandler = new CallbackHandler();
	callbackHandler->Init();

	MGlobal::displayInfo("Plugin is loaded");
	return MS::kSuccess;
}

// Gets called when the plugin is unloaded from Maya.
EXPORT MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin plugin(obj);

	MGlobal::displayInfo("Plugin is unloaded");
	delete callbackHandler;

	//delete localBuffer;
	return MS::kSuccess;
}