zephyr_library()

if(DEFINED ZMK_BASE)
  set(ZMK_APP_DIR "${ZMK_BASE}/app")
elseif(DEFINED ENV{ZMK_BASE})
  set(ZMK_APP_DIR "$ENV{ZMK_BASE}/app")
elseif(DEFINED ZMK_APP_DIR)
  set(ZMK_APP_DIR "${ZMK_APP_DIR}")
elseif(DEFINED ENV{ZMK_APP_DIR})
  set(ZMK_APP_DIR "$ENV{ZMK_APP_DIR}")
elseif(DEFINED ENV{WEST_TOPDIR})
  set(ZMK_APP_DIR "$ENV{WEST_TOPDIR}/zmk/app")
endif()

if(DEFINED ZMK_APP_DIR AND EXISTS "${ZMK_APP_DIR}/include")
  zephyr_library_include_directories("${ZMK_APP_DIR}/include")
endif()

zephyr_library_sources_ifdef(CONFIG_ZMK_BEHAVIOR_ADELHOLTZ
  config/adelholtz.c
)
