#!/bin/sh

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/.config/iamchad/scripts/bar_themes/catppuccin


cpu() {
	cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c$green^  󰞰"
	printf "^c$green^ $cpu_val"
}

pkg_updates() {
	# updates=$(sudo pacman -Sy  cl| wc -l) # void
	updates=$(checkupdates | wc -l)   # arch , needs pacman contrib
	# updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

	if [ "$updates" == 0 ]; then
		printf "^c$green^  Fully Updated"
	else
		printf "^c$green^  $updates"" updates"
	fi
}

# battery() {
# 	get_capacity="$(cat /sys/class/power_supply/BAT1/capacity)"
# 	printf "^c$blue^   $get_capacity"
# }

# brightness() {
# 	printf "^c$red^   "
# 	printf "^c$red^%.0f\n" $(cat /sys/class/backlight/*/brightness)
# }

mem() {
	printf "^c$green^  󰆼"
	printf "^c$green^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}

wlan() {
	case "$(cat /sys/class/net/enp37s0/operstate 2>/dev/null)" in
	up) printf "^c$blue^  󰤨 ^d^%s" " ^c$blue^Connected" ;;
	down) printf "^c$red^  󰤭 ^d^%s" " ^c$red^Disconnected" ;;
	esac
}

# cal() {
#   printf "^c$black^ ^b$darkblue^ 󰸗 "
#   printf "^c$blue^^b$grey^ $(date '+%a, %m-%d') "
# }

clock() {
	printf "^c$blue^  󱑆 "
  printf "^c$blue^ $(date '+%a, %m-%d ')"
	printf "^c$blue^ $(date '+%H:%M')  "
}

obake() {
  printf "^b$black^"
  printf "^c$red^ 󰊠 "
  printf "^c$yellow^ 󰊠 "
  printf "^c$blue^ 󰊠 "
  printf "^c$purple^ 󰊠 "
}
obake=$(obake)

while true; do

	[ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates) && curwea=$(printf "^c$blue^  $(curl wttr.in/angeles?format="%C+%t")")
  interval=$((interval + 1))

  sleep 1 && xsetroot -name "$updates $curwea $(mem) $(wlan) $(clock) $obake"
done
