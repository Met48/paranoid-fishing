bin_dir = "bin/"

solution "GameTest"
    configurations { "Debug", "Release" }
    
    project "GameTest"
        kind "WindowedApp"
        language "C++"
        files { "src/**.h", "src/**.cpp" }
        includedirs { "sfml/include" }
        libdirs { "sfml/lib" }
        
        configuration "Debug"
            -- files { "sfml/bin/*-d.dll" }  -- All debug dlls
            targetdir(bin_dir .. "Debug/")
            defines { "DEBUG" }
            flags { "Symbols" }
            links { "sfml-graphics-d", "sfml-window-d", "sfml-system-d", "sfml-audio-d", "sfml-main-d" }
        configuration "Release"
            -- Optimized, uses static version of SFML
            -- files { "sfml/bin/libsndfile-1.dll", "sfml/bin/openal32.dll" }  -- Just audio dlls
            targetdir(bin_dir .. "Release/")
            defines { "NDEBUG", "SFML_STATIC" }
            flags { "Optimize" }
            links { "sfml-graphics-s", "sfml-window-s", "sfml-system-s", "sfml-audio-s", "sfml-main" }

newaction {
    -- TODO: Copy to Release folder
    trigger = "copy-dlls",
    description = "Copy the Windows dlls required to run the program.",
    execute = function ()
        function filename(path)
            -- Not as familiar with lua, so I'll just run the iterator to get the result
            last_name = ""
            for v in string.gmatch(path, '[\\/]([^\\/]*)$') do
                last_name = v
            end
            return last_name
        end
        -- Create directory structure
        if not os.isdir(bin_dir) then
            os.mkdir(bin_dir)
        end
        if not os.isdir(bin_dir .. "Debug/") then
            os.mkdir(bin_dir .. "Debug/")
        end
        if not os.isdir(bin_dir .. "Release/") then
            os.mkdir(bin_dir .. "Release/")
        end
        audio_dlls = { "sfml/bin/libsndfile-1.dll", "sfml/bin/openal32.dll" }
        debug_dlls = os.matchfiles("sfml/bin/*-d-*.dll")
        -- Copy debug dlls to debug folder
        for i, v in ipairs(debug_dlls) do
            print(i, v)
            print(filename(v))
            print(os.copyfile(v, bin_dir .. "Debug/" .. filename(v)))
        end
        -- Copy audio dlls to debug folder
        for i, v in ipairs(audio_dlls) do
            print(i, v)
            print(filename(v))
            print(os.copyfile(v, bin_dir .. "Debug/" .. filename(v)))
        end
    end
}
