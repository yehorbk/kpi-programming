# Ansible Lab

## Requirements

* Python 3.x
* Python 3 Pip (sudo apt install python3-pip)
* Ansible 5.x (`sudo pip3 install ansible`)
* It's better to have Ubuntu or other Debian-based linux (for other linux distros you will need to modify package installation commands)
* Template works on localhost, but you can do it remotely on a server that is available through SSH by modifying [inventory](./inventory/hosts) (remote group) and [site.yml](./site.yml) (host variable)

## Before tasks

### If you have GitLab account
Fork this project by clicking [https://gitlab.com/DmyMi/ansible-lab/-/forks/new](https://gitlab.com/DmyMi/ansible-lab/-/forks/new)
### If you have GitHub account
Follow this article [https://nira.com/how-to-migrate-from-gitlab-to-github/](https://nira.com/how-to-migrate-from-gitlab-to-github/) to copy the project to your Github.

Doing the lab requires you to know how to use Git :)

## Tasks

Write an Ansible playbook using the template in [site.yml](./site.yml).

The playbook itself is an Ansible version of Lab 1 with extra steps :)

1. The playbook should use the `packages`, `aptcachetime`, `app_dir`, `app_file` variables defined in [all](./inventory/group_vars/all) vars file.
2. Playbook should use the [app.service.j2](./templates/app.service.j2) that you need to write. Use the `app_dir`, `app_file` variables to specify the path to Java app. Use the `app_port` variable to specifyt the `PORT` environment variable for Java app.
    * If you have created additional users for Lab1 - add the user creation to `site.yml` with the help of [user module](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/user_module.html).
3. Playbook should use the [nginx.conf.j2](./templates/nginx.conf.j2) template with a simple Nginx config. There you should write the `server` block to let Nginx listen on port `80`. Nginx should *proxy* all requests to Java app at `localhost:<SOME_PORT>`. Target port should be specified dynamically using the `app_port` variable.

To run the playbook if it's written correctly:
```bash
# If you have paswordless SUDO
ansible-playbook site.yml
# or if you have password SUDO
ansible-playbook site.yml -K
```

## Cleanup

The [cleanup.yml](./cleanup.yml) playbook can be used to remove everything from you server/vm (if you followed the template and did not add additional packages).

```bash
# If you have paswordless SUDO
ansible-playbook cleanup.yml
# or if you have password SUDO
ansible-playbook cleanup.yml -K
```

## Submission

All i need is a link to your Github/Gitlab project in Classroom.