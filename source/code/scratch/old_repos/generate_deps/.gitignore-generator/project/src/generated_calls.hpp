if (All_Are_False(NO_OBJECT_FILES) and Any_Are_True(YES_OBJECT_FILES))
{Print_Vector(outfile,constant::OBJECT_FILES);}
if (All_Are_False(NO_DYNAMIC_LIBRARIES) and Any_Are_True(YES_DYNAMIC_LIBRARIES))
{Print_Vector(outfile,constant::DYNAMIC_LIBRARIES);}
if (All_Are_False(NO_STATIC_LIBRARIES) and Any_Are_True(YES_STATIC_LIBRARIES))
{Print_Vector(outfile,constant::STATIC_LIBRARIES);}
if (All_Are_False(NO_EXECUTABLES) and Any_Are_True(YES_EXECUTABLES))
{Print_Vector(outfile,constant::EXECUTABLES);}
if (All_Are_False(NO_BACKUPS) and Any_Are_True(YES_BACKUPS))
{Print_Vector(outfile,constant::BACKUPS);}
if (All_Are_False(NO_DEPENDENCIES) and Any_Are_True(YES_DEPENDENCIES))
{Print_Vector(outfile,constant::DEPENDENCIES);}
if (All_Are_False(NO_WINDOWS_GENERATED) and Any_Are_True(YES_WINDOWS_GENERATED))
{Print_Vector(outfile,constant::WINDOWS_GENERATED);}
if (All_Are_False(NO_MAC_GENERATED) and Any_Are_True(YES_MAC_GENERATED))
{Print_Vector(outfile,constant::MAC_GENERATED);}
if (All_Are_False(NO_LINUX_GENERATED) and Any_Are_True(YES_LINUX_GENERATED))
{Print_Vector(outfile,constant::LINUX_GENERATED);}
if (All_Are_False(NO_ARCHIVED) and Any_Are_True(YES_ARCHIVED))
{Print_Vector(outfile,constant::ARCHIVED);}
if (All_Are_False(NO_DATABASE) and Any_Are_True(YES_DATABASE))
{Print_Vector(outfile,constant::DATABASE);}
if (All_Are_False(NO_NOTEPADPLUSPLUS) and Any_Are_True(YES_NOTEPADPLUSPLUS))
{Print_Vector(outfile,constant::NOTEPADPLUSPLUS);}
if (All_Are_False(NO_VIM) and Any_Are_True(YES_VIM))
{Print_Vector(outfile,constant::VIM);}
if (All_Are_False(NO_EMACS) and Any_Are_True(YES_EMACS))
{Print_Vector(outfile,constant::EMACS);}
if (All_Are_False(NO_KATE) and Any_Are_True(YES_KATE))
{Print_Vector(outfile,constant::KATE);}
if (All_Are_False(NO_SUBLIME) and Any_Are_True(YES_SUBLIME))
{Print_Vector(outfile,constant::SUBLIME);}
if (All_Are_False(NO_AUTO_TOOLS) and Any_Are_True(YES_AUTO_TOOLS))
{Print_Vector(outfile,constant::AUTO_TOOLS);}
if (All_Are_False(NO_SCONS) and Any_Are_True(YES_SCONS))
{Print_Vector(outfile,constant::SCONS);}
if (All_Are_False(NO_CMAKE) and Any_Are_True(YES_CMAKE))
{Print_Vector(outfile,constant::CMAKE);}
if (All_Are_False(NO_QT) and Any_Are_True(YES_QT))
{Print_Vector(outfile,constant::QT);}
