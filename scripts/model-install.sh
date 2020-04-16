#!/bin/bash

set -eu -o pipefail

shopt -s failglob

local_path=$(dirname $0)

[ -n "{${1}" ] && SYSREPOCTL="${1}"
[ -n "{${2}" ] && SYSREPOCTL_ROOT_PERMS="${2}"

: ${SYSREPOCTL:=sysrepoctl}
: ${SYSREPOCTL_ROOT_PERMS:=-p 600}
: ${YANG_DIR:=$local_path/../modules}

is_yang_module_installed() {
    module=$1

    $SYSREPOCTL -l | grep -c "^$module [^|]*|[^|]*| I .*$" > /dev/null
}

install_yang_module() {
    module=$1

    if ! is_yang_module_installed $module; then
        echo "- Installing module $module..."
        ${SYSREPOCTL} -i ${YANG_DIR}/${module}.yang
        ${SYSREPOCTL} -c ${module} ${SYSREPOCTL_ROOT_PERMS}
    else
        echo "- Module ${module} already installed."
    fi
}

install_yang_module module-versions
