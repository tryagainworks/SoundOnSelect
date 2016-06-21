#include "clsglobal.h"

clsGlobal::clsGlobal()
{

}

QString clsGlobal::fnGetBasePath(){
    if(QSysInfo::productType()=="android")
        return "/sdcard/SoundsOnSelect/";
    else
        return qApp->applicationDirPath()+"/SoundsOnSelect/";
}
