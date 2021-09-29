#!/bin/bash
set -e

function usage() {
  cat << EOF
Utilizzo: $0 [path]
  [path]  Percorso della cartella dove creare l'esercizio.
          Il nome della cartella verrà usato come nome dell'esercizio.
EOF
}

path=$1

if [[ -z "$path" ]]; then
  usage
  exit 1
fi

full_path="esercizi/$path"
name=$(basename $path)

if [[ -f "$full_path" ]]; then
  echo "La cartella esiste già!"
  exit 1
fi

mkdir -p $full_path

echo "Creazione file da template:"
for file in $(find template/ -type f -printf '%f\n'); do
  source="template/$file"

  replaced_name=${file//"[name]"/$name}
  destination="$full_path/$replaced_name"

  cp $source $destination
  echo "* $destination"
done

echo "Esercizio creato in $full_path"
