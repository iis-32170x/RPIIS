#!/bin/bash
directory="$1"
N="$2"
X="$3"
q=0

end() {
  echo "end"
  exit 0
}

out() {
  ls -l "$directory"
  for file in "$directory"/*; do
    if [ "$q" -lt "$N" ]; then
      ((q++))
      rm -f "$file"
      out
    else
      w
    fi
  done
}

w() {
  q=0
  number=0
  for file in "$directory"/*; do
    if [ -f "$file" ]; then
      ((number++))
    fi
  done
  
  if [ "$number" -ge "$N" ]; then
    sleep "$X"
    out
  else
    end
  fi
}

number=0
for file in "$directory"/*; do
  if [ -f "$file" ]; then
    ((number++))
  fi
done

if [ "$number" -ge "$N" ]; then
  out
else
  end
fi
