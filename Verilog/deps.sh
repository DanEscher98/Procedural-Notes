# Exclusive for Verilog dev
declare -a DnfDeps=("iverilog" "yosys" "gtkwave" "inotify-tools")
for pkg in ${DnfDeps[@]}; do
  sudo dnf install "$pkg"
done
npm install -g netlistsvg

# General
gh install casey/just
