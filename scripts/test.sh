/home/john/.customsh/weather.sh
state=$(awk "NR==3" /home/john/.customsh/weatherboy | sed 's/[^A-Za-ln-z]*//g')
st() {
  printf "^c#00ff00^ $state"
}

xsetroot -name "$(st)"
