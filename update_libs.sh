#!/bin/sh

function clone_or_update() {
  echo "Updating $1 ..."

  LOCAL_REPO="libs/$1"
  if [ ! -d $LOCAL_REPO ];then
    git clone "$2" "$LOCAL_REPO"
  fi

  pushd "$LOCAL_REPO"
  git reset --hard $3
  popd
}

# update kazmath
clone_or_update "kazmath" "https://github.com/Kazade/kazmath.git" "master"

# update cml
clone_or_update "cml" "https://github.com/demianmnave/CML.git" "v2.1.2"

# update eigen
clone_or_update "eigen" "https://gitlab.com/libeigen/eigen.git" "3.3.8"

# update glm
clone_or_update "glm" "https://github.com/g-truc/glm.git" "0.9.9.8"

# update bullet
# ??
