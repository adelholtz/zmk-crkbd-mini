zephyr_library()

if(DEFINED ZMK_BASE)
  zephyr_library_include_directories(${ZMK_BASE}/app/include)
elseif(DEFINED ENV{ZMK_BASE})
  zephyr_library_include_directories($ENV{ZMK_BASE}/app/include)
endif()

zephyr_library_sources_ifdef(CONFIG_ZMK_BEHAVIOR_ADELHOLTZ
  config/adelholtz.c
)
