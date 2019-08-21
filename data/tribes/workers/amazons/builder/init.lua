dirname = path.dirname(__file__)

animations = {
   idle = {
      pictures = path.list_files (dirname .. "idle_??.png"),
      hotspot = {6, 18},
      fps = 10
   },
   work = {
      pictures = path.list_files (dirname .. "work_??.png"),
      sound_effect = {
         path = "sound/hammering/hammering",
         priority = 64
      },
      hotspot = {9, 24},
      fps = 10
   }
}
add_directional_animation(animations, "walk", dirname, "walk", {11, 24}, 15)
add_directional_animation(animations, "walkload", dirname, "walkload", {10, 24}, 15)

tribes:new_worker_type {
   msgctxt = "amazons_worker",
   name = "amazons_builder",
   -- TRANSLATORS: This is a worker name used in lists of workers
   descname = pgettext ("amazons_worker", "Builder"),
   helptext_script = dirname .. "helptexts.lua",
   icon = dirname .. "menu.png",
   vision_range = 2,

   buildcost = {
      amazons_carrier = 1,
      hammer = 1
   },

   ware_hotspot = {0, 20},
   animations = animations,
}
