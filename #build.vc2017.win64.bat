if NOT EXIST build.vc2017.win64 mkdir build.vc2017.win64
pushd build.vc2017.win64
call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x64
cmake -G"Visual Studio 15 2017 Win64" ..
msbuild skibin_k_s.sln /property:Configuration=Debug /m
msbuild skibin_k_s.sln /property:Configuration=Release /m
popd
pause