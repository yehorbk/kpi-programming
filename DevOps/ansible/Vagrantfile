# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/focal64"
  config.vm.hostname = "vagrant-ubuntu2004"
  config.vm.define "ubuntu2004"
  config.vm.network "private_network", ip: "192.168.56.222"

  config.vm.provider "virtualbox" do |vb|
    vb.name = "ubuntu2004"
    vb.memory = "2048"
  end

  config.vm.provision "ansible" do |ansible|
    ansible.playbook = "site.yml"
    ansible.inventory_path = "inventory/"
    ansible.host_key_checking = false
    ansible.limit = "vagrant"
  end

end
