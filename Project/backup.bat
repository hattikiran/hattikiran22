set new_dir=%date:~0,4%.%date:~5,2%.%date:~8,2%-%time:~0,2%.%time:~3,2%.%time:~6,2%
set proj_folder=Builds_DEOS_2.00.02
xcopy "%1\..\..\*.c" "%1\..\..\..\%proj_folder%\\%new_dir%\" /S > nul
xcopy "%1\..\..\*.h" "%1\..\..\..\%proj_folder%\\%new_dir%\" /S > nul
xcopy "%1\..\..\*.bin" "%1\..\..\..\%proj_folder%\\%new_dir%\" /S > nul
xcopy "%1\..\..\*.out" "%1\..\..\..\%proj_folder%\\%new_dir%\" /S > nul
xcopy "%1\..\..\*.map" "%1\..\..\..\%proj_folder%\\%new_dir%\" /S > nul