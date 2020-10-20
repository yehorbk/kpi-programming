# Гість

## Пошук публікацій
#### Користувач, що знаходиться у гостьовому режимі має змогу шукати публікації про заклади

**Передумови**. Гість хоче знайти інформацію про заклад та відгуки

**Результат**. Гість отримує інформацію про заклад та відгуки

1. Гість натискає на кнопку "Пошук" у головному меню
1. Гість вводить запит
1. Система отримує запит, обробляє його та відображає результати пошуку
1. Гість отримує результати пошуку
1. Публікація знайдена, гість може проглядати фото та читати коментарі

![UC1](http://www.plantuml.com/plantuml/png/SYWkIImgAStDuSf9JIjHo4XDJ4ajuh99oyyhKKZEpyaliZKmC50epgnAjJMqiBD9iWj8JCvEJ4-rij5FibDmBqqjBk72eTmCfDpJ1Q8or5dN451AjUCq34J1Va-n1-04kE4mq087SE7Oa514H0AKZWH4IRFn9rb_if5oWdatuhriWkLOif2eDj7EpfitC_8G3kyms225yNWiuUY94bGQEpvMg6cE2eR6V9Q3L5yqOTm8MrXKi4V2LvhJY6AQNcXymifl56XW1hcMA2XYN4u9OntIFf-cHpWUMMXii8L1oSnMiymjFS3nyyRBfcVP9O8Je4656WQvPhJHI1cV8vEDOGSbVQ30Xd4rJUKfnJr1S7n4i6WeeRV_AHcKiX2NnHNn6gNc-MCKOW954jD1cL8tjzUdPgcmrHcgG_dKfPRqAPPG96AMp8Vmxb1HelVVRHlsTQ3amGjIEEImGkItsCaVlbLXDzzGy8kE8osUo-2m4YiW5Pl9PGc73AvZXmSPh27oA3hF09OTFOca9EWisbFmDmP-j3olFir-MuRSMyqhP6tqKj8rYcE-o6GfHle1XnR4fzLe0jlEhXZT22F5Fhv0SJvtzu6wulpu2_43)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC1.pu)

## Реєстрація користувача
#### Користувач, що знаходиться у гостьовому режимі має змогу створити обліковий запис користувача

**Передумови**. Гість хоче створити обліковий запис користувача.

**Результат**. Гість створює обліковий запис користувача.

1. Гість натискає на кнопку "Обліковий запис" у головному меню
1. Гість натискає на кнопку "Реєстрація"
1. Гість обирає тип облікового запису "Користувач"
1. Гість заповнює ФІО та поштову адресу
1. Система надсилає лист із кодом підтвердження на вказану поштову адресу
1. Гість отримує код та вводить його у поле для коду
1. Гість заповнює інформацію про себе: біографія, рік народження, адреса, фото та пароль
1. Система записує дані до бази
1. Гість отримує можливості користувача

![UC2](http://www.plantuml.com/plantuml/png/hLPFJnDV5DtFftZXjmL-fIJ6y8UGg37kt9YuCmDCWOZKbB8nB812TK5Aear9Z8A8YTjfRM5efzElSDytyfpt7g5DOVo32vBttjnxxhdd_g7p6qM_KDnyjUQj1RcYMWdyfQ3WpUJowqMrc5_B5sOpcOpQM7qJp4xSdvjPc7lgBxxqbuEfcVyNvjJZpM2ZwDrYVe_cJnvQosSFnh9fTl9PGhcGXeJMNhv8IrVrZjxLsnBgigxfGoLjIN2Dp7E9nlgjXAcmPxJGEzAL2DwH0_y0E68SZ2evjNZIalWNM2UWj0sx9cB7aaXZ64_fVKaGigKCPiFonIbISAXBHzUaRLtbKY7XK7gC_nUfKI6vW6r77o10g7U7o5npq1LT_VSCtbDK85PWsTKrn9E8pgvWHuRGhGZgqVCNcSoKae_3WG6bc1Hh9Z7LQ-BITHVOd5DYv8cu9LrDZp5XOqXJIPrwIKA41Yk9lowlNHnwx3JgGaNDiqh7pGBtH4Au9PJLe53HEYJ-WVSAYu2i3jDX9W5JbSIbtsEg2PXo7leIr_iW3U0cx4gG1dhBPUheoJ7bCQNkccB3iyo4IPdUjZnUiBvqDVVUrdNtR7bcDNXWXzba2mEkZLDL4OBzGl2Uj7L9ZSXnIc-DA9X04iZaw2GIyoac7LsP_jqWDoo54UFCw14VuKWKoZZOxGdZzt4YtasTP_6EQ6Qvsj7v9cKvDYsf-46_mn6VWGBB9jS28QUzzNmnK6QL_kVxkPpl3rIe42onCae-mVaSQaHaPWV1r87khCB0Kjfoyh3sx4uhJyUQA6HueKoIJSeAUkmI3hvPLqt4OSsx-j19sg3058ApavxDO3zGPqhFAUJKkQXE5KuKEKGqLdBf57SXGBV5NkwGXd6xareJrseDLmkIuB1dQXkxFgaepZVvx42EkhJWXZabITCsU-obKMK6ess4edM_UgDzsaW8KmQ0R5TDOJsuE-wGLpQr2rocVAN-RZVesk3ASE4BgyihVnn_SY1-QktZVcTZLhlbVyWqDad-DRh9Kihb0OzT8zyXfMjJfo4xbmM1B_GSDmovfAcgBM3BhJ2pkHbJ6XvcuwkSoHct_8cKMVvuNChZSegJOGG-1pon8prOHVGRosQoTkeSetcSyKle9m00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC2.pu)

## Реєстрація представника
#### Користувач, що знаходиться у гостьовому режимі має змогу створити обліковий запис представника

**Передумови**. Гість хоче створити обліковий запис представника.

**Результат**. Гість створює обліковий запис представника.

1. Гість натискає на кнопку "Обліковий запис" у головному меню
1. Гість натискає на кнопку "Реєстрація"
1. Гість обирає тип облікового запису "Представник"
1. Гість заповнює ФІО та поштову адресу
1. Система надсилає лист із кодом підтвердження на вказану поштову адресу
1. Гість отримує код та вводить його у поле для коду
1. Гість заповнює інформацію про заклад: назва, розташування, власник, документи
1. Система записує дані до бази та відправляє запит до адміністратора
1. Адміністратор перевіряє інформацію
1. Гість отримує можливості представника

![UC3](http://www.plantuml.com/plantuml/png/SYWkIImgAStDuSf9JIjHo4XDJ4ajuh99oyyhKKZEpyaliZKmC50epgnAjJMqiBD9iWj8JCvEJ4-rij5FibDmBqqjBk42r5ezFKryKNG_d-A5txOGAEItW8s9kl03cBWpJG1r0uQuP04TAIwQrcW3YH4gOk9s6APqsawdN-6yR-GzxzqurDA9IbnetflUU-wvv_vvp37_d-PF7ddBfmyNLyliS8O8VSI8l3s-e6Sxzj3MxG4Ysx0djcqmaKiF2JyZ4kCnKWmHbG9VscC1E5JRLE4_2Y31cnM32wGy2tA6IExlaI2p9nZJHWdKaTk3qZXTz9HTA3WvujbOnXuX5pezmpjYOYALKsh4uGeZ2JhqhXWOaIF2XDp-Ad4gYBuD1RL9BrkVeLEmi2tR-HSSFZYRaS0VKqw9o7njg2KzTPJc8fZ7pvulBwyRV5AbI3jaazXZWJ8amfeYeuA9NCPw4PiRoYoPIjpGTifZhFWOI0okg1Xo8iHCL_wDUHtBWGf4L8QQki-c7BSgk5r4ufPJM8T2JQz4v6lvtc8P9AjsESogm7IGQ_eJffeBKpSnHUBsI4WBC2iKsZhrng0SU6szfDiLZJyI7d7H3VNIcSSvLKUkFJ9WdpMe8vKWAL_rO6jdq-Z22VQBjjmFt4uAXDiPkR3kR3Hsg40OEHDyWg4DpGBEIvfsmOW9hgc-qicHyLD6EhQryPj1xjf62ywPqLFvI4UYOFBh6EMCVukJm-lUDKiUyPI6dgsVoczeuDpGqF07-uxbGSmq8YG48kX6iBFxPikuBVvVhRQzNQjDrMXlQvErCVWipZUYHqfkVi9S9UZEEanjmtqLY5JPzbwWaJSnacFVk3GJ2Ylqs31kft0N9hYXp997MqMDAJ6bu52MPpFT4LIQudEyESuQLLNXg993IcE3WMgk8J3Yq2LIahQwtKkjbKAjEwhb1kcjMrUPTahBhKxj0Mv39hfEHVJ5gnZ-Z3wJ4JtSWlEoLPZRg7Y-AcxqsPFQmNmww3QpoYS_jqxp7hbMIpj3i-TNraGNaJsPsa_AJtU9Rb3MGXoAVQ8kqRnTX4Yps7lrukKVfx4wbSRSXUTIqcUSV4NBzfoIteVDsXIRqYRFRZlJZE8EPnz3aKUMvkvh6HjFQNjNu6Mjuhkae_Ee6yJLuLgk8PjaoJ7aCyTMqKTUjtN2_naJSO0pVCKbBlbETj6WADaI6akua9DZ97oQF77q0h5AwRTONQxwzQAC7iXP_jhy0G00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC3.pu)

## Авторизація користувача та представника за допомогою пошти
#### Користувач, що знаходиться у гостьовому режимі має змогу авторизуватися за допомогою свого облікового запису користувача або представника.

**Передумови**. Гість має створений обліковий запис користувача або представника

**Результат**. Гість авторизований у Системі

1. Гість натискає на кнопку "Обліковий запис" у головному меню
1. Гість натискає на кнопку "Авторизація"
1. Гість заповнює поштову адресу та пароль
1. Система перевіряє отримані дані із даними в базі
1. Гість авторизований у Системі як користувач або представник

![UC4](http://www.plantuml.com/plantuml/png/bLNFJnDH4Bw_l-85huAbCSPG82HgZ3Sl9jxC0biW8ZMbN0m7wCRgeG6YP4cCWCZ1wsDfxL9B-o_C_4VED_i8gT0D7ahUlZS_lldccs5klHPKQnllLirgMAxPvJ1O3AjckbnPgzc5ocgbEbCe5EpwoeTmPlBnxFJyxCjWuMsm54vDFvYVjSytmlMQ6M7-2EOldcQMhvwCFyopeqDorA64N6PFUvHmdVgyHQdSEsvmpBkMkjaLRtET8vZp9t9MB9sbWRoqgOKtSl9sAQvTF7JmfqLz6iYl9xzpYR9ZyScVnJZDHNQA5BpjmwKUtrUE5KJplgMJ312r9RZBZNLCRGyoKY39pNWMGNZVQiH4osrhxWih3cVqXsFggYkkK1iDa7yKD-J4gJ-IdLouFyIZmv7aRCABwndO8RHkg570vJnSZeQeuJWtrnVWaKmxWlgIOwcVKXJYUt-WgKT6iCzUloaKfYnzkqc2X5A5e7j2RYfQy1Zn8OUsHJcIDUBz_0oJac6Vd0AaCp03QXDAGAtsgQy1bMs77e4xNEV7BMhSlaSzKBLA0fs9QxpyKN9nh4sCk0uKT65oMJr2NUYAxubuDXIduoruPwoQS6tnQlRDvdLtDusk1oFe3j5-y4fTbIT2G788Fg2kz7gCZdBaEGOvOF106U1W577L0npUATqroQsBOKpT3v0CqH4Gxdx0SOLKZbeO0h1tjJB00p1nisJMAhNGwXgy5mJbSX0CCLiD5y6efUzY_rkgI36TcUxkQZYfH2CFQ1vQ6viemAy7D5dQiuiI-bpNKdjNgclvW_3S-KV9YPSCnxwOwihIydzNKxm6EQG50Dox-x1RtgNkhKifVoMLH7ELzoLZCl3bYW0HLT8lQcCXWY7VEqm2dSjdX3vEQ2sOGdJJ1_TYrz4K034bHaJsaqxf5AlYc1hWiJT1ZGawaPEY5JnDdA1M8rOf_CQBXM91cV68vkGi_pV_0W00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC4.pu)

## Авторизація користувача за допомогою облікового запису Google чи Facebook
#### Користувач, що знаходиться у гостьовому режимі має змогу авторизуватися за допомогою свого облікового запису Google або Facebook.

**Передумови**. Гість має створений обліковий запис Google або Facebook

**Результат**. Гість авторизований у Системі

1. Гість натискає на кнопку "Обліковий запис" у головному меню
1. Гість натискає на кнопку "Авторизація"
1. Гість обирає авторизацію за допомогою Google або Facebook
1. Гість авторизується на сторінці авторизації Google або Facebook
1. Система записує дані до бази
1. Гість має можливості користувача Системи

![UC5](http://www.plantuml.com/plantuml/png/bLLDJnDH5DtFhxZ1hM0XqPZo4H8_Y3it9kxC05CWLCQqmyQmA6siBaWnIeR428Wit8wbjGEqz2_SzuyyXpT4HZiJN3IPUNFkFUVUU-xhV3LmAy7cwx9Jzag1h7hkibTnPah-HY1BVjclp1OA1QcklVLc9n_EpIpEFNUNrjqLhpXpRt5E5ZQzQk1am1yG_konHRvuD7u_3wS76cbFsnfPl7xKjgdhfQbfZFF8D4reTaNFxP7PDdNJ8DoyrqY84EtefGxnw-Dt2bnByF1JBqp8C6tROo4OEEPeo8BlhvGzGPPOdhfBtgBlh-VgF26XsTQ1niWQ9se_GnqbxTmLFRRoj0iXKMwk8-sQ6d0TbDAdmd_p2PEOFU4RAo2Ut7hsLt4ykb7QTM4Q0NHvkzA-8NNFD91p1sIHgLinAJLHQYpaZH8vff4gtOIvN9_OFZ2rqCw12L4VGZbIE-dzA-hC3FBavQj2ePXH9Dz7cgV73-ov-O0F5vmZQa87Uv8OXwUqM2kVUh8ekWUOTU5GQ3s11beunfjjYdadq15gXqupTTQfPxdReeTq5jkQD1MHJGuSKckCjcrnl8tbwrLrjlwCPykvscO7wWuuFqu3vT0_JC7jOVAXdcDOOtgOuvynpfFheXTM3jl3epxbcDRqBKb6x_4OmycFu1f3Hu-ibRNO6ODdrZGX-hx7pg0_krOUdlYLtHoGP3JpVYQ3i-47dl2ob3kkMogvRcgW5M-PWnJz2gs_qBoOMslzoh49mpcqr2snHU7xrxsdwCH49anxQzhILzPMLl-RV_86VyeqHQ3j4FetWgoxmwmhDrK0T5K3_mswOvMLVB30c_f3ku3OdQipQiXzq5EyOcyqch12EzhbhSFFDM2jvNaue0HjEx3QTptH4z4lUgHDxcn_GfiJUcn2Av2hp2SQn04gPjpuL67AjZrHD8zd_Ddz1W00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC5.pu)
