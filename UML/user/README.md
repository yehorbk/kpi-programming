# Користувачі


## Редагування облікового запису
#### Учасники: Користувач, Система.
#### Передумови: Користувач бажає редагувати профіль.
#### Результат: Дані про користувача оновлено.
#### Виключні ситуації: 
ЕХ_00: Некоректний запит;
ЕХ_01: Доступ до бази даних відсутній;
ЕХ_02: Некоректно введені дані;
#### Основний сценарій:
1.	Користувач переходить в обліковий запис;
2.	Натискає кнопку "Редагувати";
3.	Система надсилає запит про дані користувача до бази;
4.	Система надсилає форму з полями, які користувач може редагувати самостійно;
5.	Користувач вводить нові дані;
6.  Натискає зберегти;
7.  Система оновлює дані;
8.  Користувач отримує повідомлення про успішне оновлення облікового запису;

![Редагування облікового запису](http://www.plantuml.com/plantuml/png/hLLDInjH55txViM3ReL6Yo9-YDIsq4tffj1T6Sqa1cCYIQJGMZ36Zov4GMo4qjgMqbKtIJHcpEW4_0Nt_QEUatbscf1CkwWIvcNUlUUUU-vvBml5abCeRQnbjL9PDrNIAwwJT0jgDfNFbVHoFfilp2KI2LtCl77dngRcPvVcdplBgqxQdPwzlpIlNnI71ayo-EaZ6xVu82vCFajDMjAGMXWkNwKf5tXtRYfyApToOuwq158NtrIbZLK3dtC9jBImtn7Fb4qbjiPtioyrKmQM1m3FLleeWTaIPc-7jSp-g9PluHkmk9PQBEeNQI8VR95zJLfno5hg87k9vOd6Na-FgEPfwU1rO7RGesyEOWjJeXPI4OTKfDko9vJBL2sKbdO_3Sf0AM-4R7t0O1LRwfYAeT0XKWaD4JsY0MlFLCrfj_9GXCSlNoKIqnepRbeoU88ovt0LZMyx5c1icfq5jekEXd91g6QBib57u9bTBGreTq4pi0JMLx6uumE91O31F-VJ94XO08jOcSvCEHJLjWOIUyo7J5ia4ihavf9tfqmLLpEvTQVWh8qKLvna_dKcbzOf9rjqentzB5zozLiryX3dBbt8R-IIYwokxwMc9YOdfjJ84p2wUzNzK--KsXnalqtLFUuAFLlRcbq9q1kdUO2U-qvOxu3ACqfHBNgDNn537-F1fZkGhg9lV_OVNSRU-ZCgnpPunIZvXF1ByO7UeD8Vv0SCqjM5GU3UU_msRLLELJpaiMfa6slqtoCQvlWUnrW-XKnwPGYXiOZGeFfcXqNa6ZrB2nI0u9iZqFL6DPxj8Jmq8bYhgO5LunVkqXoXwrf0hAABm-X6gFESSwV1aI6iQMz3DWGOrAq0iHxU7lJ-Dgi2kuq-Xpe1FHrZ7Kq_jEuVNl_hpCOZYGOP0ruubRgz7i__am_Ex0dZPNGIKOrhyymAWbanfHEsIVM0waToXZP2K9awclUKkl-U_ATV8R0fblBhCse1lU2tzHS01)

[UML-діаграма](https://github.com/eve-va/kpi-db-subgroup/blob/master/UML/user/Diagrams/edit.pu)


## Пошук публікацій
#### Учасники: Користувач, Система.
#### Передумови: Користувач бажає переглянути публікації.
#### Результат: Користувач отримує доступ до інформації, що його зацікавила.
#### Виключні ситуації: 
ЕХ_00: Некоректний запит;
ЕХ_01: Доступ до бази даних відсутній;
#### Основний сценарій:
1.	Користувач переходить на головну сторінку;
2.	Вводить запит у поле пошуку, за необхідності налаштовує фільтри;
3.	Система обробляє запит;
4.	Система повертає публікації, що відповідають запиту;
5.	Користувач отримує сторінку з публікаціями;

![Пошук публікацій](http://www.plantuml.com/plantuml/png/XLHBQnDH55xt_eeBRWkcO4lfenIhWXjn8xYJQJDvq7IcpAG86Y7DD8r2iL1Y1D5M4VVJDjDCcaV-mhd_oE_St6XIacasSsVk-HxdSRBf5oslUB1Na48Kx4nHvcmhRNjYBUCwHRdZ5bnlFPLAIJ__pbvVMDvOszvuQUtiMbbxPUtXzePyvSyCNkBWvqzCtDQZf33wGI6rw8h2OJXTK5zzL07TIXhWSKaTrQ1R2jKndkr4gj-gXhX3wb4CH6m8lu6mJB4wL1NmGKZLvYNz6dwXYBeK9h9UK0HyH4sWkzG7GmApXE6GRd2imxz1NYE7K-gf07hnbBJKrqG3Fq7HKW4G9o08LIL9leyNVAGkr62XINrpFz0l4gezTQIHtP7wl5IVS4LjP7VDXvQ-qVuuNUhSKw8pBZZyVLOri3SaUX1hKIEW3SzaUFhwJIgr8Z494LZWZ9-gejlOrcPem7o910iWgDzDbfi1VCnl8VEfggGh9DP4NC0IzyxKkPudTDtO0V2O8ho4gipWOMgsanxjZ_1tyyw-vLbxStxEIhjlyqvMPgo2R_-_aI_SeYtVYxd7sAYivnuuwIrMbmyooujBYyjYxXaSZJxfd_WWH6bQoqj2Bx90_cPILHL-cxe39vATIkugTOPPg40od8bu5b3fO5Km-Wot_t1ZPPT0uCG44GvcFG6Rrq6i4E7sKbMviDGpJMXeQHuTn5TOMq-aEaAKdcHEP5KuN0d-_n7q7K4t0CHiHD8N-eEvqANb8AG_kRGbDdqEtJAhw-chZzasr5u-cvl1lJ36hQi7Zrn1lMJrQNjgDiNC4DV2d4A8JrODLPtPCFOziQPt6mAUQVAdrEMIeU7k_ghOX7lyVVy5)

[UML-діаграма](https://github.com/eve-va/kpi-db-subgroup/blob/master/UML/user/Diagrams/search.pu)


## Збереження
#### Учасники: Користувач, Система.
#### Передумови: Користувач бажає зберегти вподобану публікацію.
#### Результат: Публікацію додано до списку збережених користувача.
#### Виключні ситуації: 
ЕХ_00: Некоректний запит;
ЕХ_01: Доступ до бази даних відсутній;
#### Основний сценарій:
1.	Користувач натискає кнопку "Зберегти";
3.	Система оновлює розділ "Збережені публікації";
5.	Користувач отримує повідомлення про вдале збереження публікації;

![Збереження публікацій](http://www.plantuml.com/plantuml/png/XLHTQzDW5Bxk-oiEU2lONdIKjIl3gU2DU2Du9zcQVh0k6Kc7e1Ms5RSRcI2p1T5D4Q-yoMO_iduqi5zmtd_aSv9iexJD2g79ctEUvpdFEIVhRiDm6dixTLAgRfORL3MDakceGjcs6hHbrsrdBPrEarjxPwvbSiN2Pl6biRLjLCpLmgFD8hrobmQlIF3p9t7SHZOfZ7-mnmE-P2yAvmvVS4_lSu_xk2OyqPyJyt_hO_Rq0I9z7h8VetpZAJ1yVQ0FTKlGzV53ub_H2N37x2MYdiSQkiWUynG82SW4oHxtSNjAFBZL_mzCFY4a040N5w9GJeiuGEO5ZtIRXqWwqcrzagZc9z06o1dfJy3qz66ivNmUXuG95vXu6ZuGp0b4C0-5Up3hBrvy9AJF5NMFGL_4Rb2V87AYsqBYItAienCgN8hmzFMRT7gLqFnUp8r_b2PDl1AD7WU2bmYG0S0faYFHGLIic8nydo8Fel8kuL0NSIsXmFrLOcbdCatIyrWE4e_4AfIsBybHQQPLkbaPvMxNh5t3CNPIRjKesMzhLeNAHjqrxzxG2xjXqdkLUembgZZsdbNQ47PwKCvbLx8vbNe6HJT7uKzzKAgvQDwQAjnT9GRAD4JDZSPl64eFmbvV_-NEx3HUZ_BA4Y6oyOg_8xJF8_Q12-k-yX-q9QnCWi0-kp5DOJoBlK7hmKV0diBlBemP2U7i-iBiHTFUkTNXr2hL9K8oTqAM-Y1wy8np7kiMzCYkHUt6_nY8yIS4BqGf8H5p8UVpcu2mXMBp2dxRktcr3a7uOFu7)

[UML-діаграма](https://github.com/eve-va/kpi-db-subgroup/blob/master/UML/user/Diagrams/save.pu)


## Бронювання
#### Учасники: Користувач, Система.
#### Передумови: Користувач бажає забронювати послугу.
#### Результат: Послугу заброньовано.
#### Виключні ситуації: 
ЕХ_00: Некоректний запит;
ЕХ_01: Доступ до бази даних відсутній;
ЕХ_02: Некоректно введені дані;
#### Основний сценарій:
1.	Користувач натискає кнопку "Забронювати";
3.	Система отримує дані про послугу, яку намагається забронювати користувач;
4.	Система перенапрявляє користувача на сторінку системи бронювання;
5.	Користувач вводить запитувані дані;
7.  Система обробляє дані;
8.  Оновлює дані про послугу, яку бронював користувач
9.  Надсилає повідомлення про вдале бронювання;
8.  Користувач отримує підтвердження вдалого бронювання;

![Бронювання](http://www.plantuml.com/plantuml/png/hLLDInjH55txViM3ReL6GH4_H6fRwAPqK-YkZ6OIWp4ZCoE5re9MgXinLAn2QRMbTDNDPCoOCOaJy1VSzuzwxhmndTJCY51TvF7UlUUSU-wzoOBZ6hQxiLQLGbJDaYjNJADescAsPDLSkMnLBNkkK2X8f_BMd1kRcfzTcdzXBAyQPNDwzk7Il7pfP0PFSl2pnqdSucHU67qZZrhaawV3wPFQeeYkr07VqHLEzTpydsgFFBMDo93Q52OeNoW2JgYsrGUrmqXgRrJI3tr30NN9oqKzem3v0JMHtOKUFmzPKWDIBt0yajJ2iP6k0NmXXP9w545c1qddQYUN_3k8MuZhg7qa0o2XFaiZ33BjKvJu5UL27x9BW3XGUyWwbi0BkH2mxAfZTH8pPI8yUVMwK9YMw5a05FZ0dv38tbzgGJt6omKO0y0HHOc1FKbDYhI3BRQfoLK0vACaNnrJ4t4xJ87pPIxk-51X4M3m7m0tO11DW4EkJQSyK6nfKXf4x78-RDfY8TecirQysHhXh5PgwuPjh8quAqRHUbEfbMN9g3hctnVvt79D-KwCFC8UbMrherPSP7Rve3GrCJan9KQUGj7DLVmdtWknEMpaDaMyle9hrYC6nMqzWUrOUe_Q69BhttGoR22lEpEYnd9uzGLznUi5TL2hpuvzfbzeT5mV1q73uEfiCkyfr40LTT6Vexwjc7Fc-cVSHwMgnthOGaQWSzOAX7sWrZEs1gNShZpHRLVAAnd2nrB2fsL_bPcPjNdaGrOTceV1anThb7p7h-Zs5Il7HSe1I6lS_fwQoMmMP1ooGhWKSj6fNT510wDvPsl6xsfDegwX2qq1wrSzslWMk4VZ1klr_qzlCBkyuGZfwDa5kLvxV7Pn6MXd--9ybiltzsp0xNdjCGjSytayW7hHv-gJH9ZIA8l8SQtr6R60Sl0R-WS0)

[UML-діаграма](https://github.com/eve-va/kpi-db-subgroup/blob/master/UML/user/Diagrams/booking.pu)
=======
# Функції для зареєстрованих користувачів
## Коментування
#### Учасники: Зареєстрований користувач (представник організації), Система.
#### Передумови: Користувач авторизований.
#### Результат: Коментар користувача додається до публікації.

1.	Користувач вводить текстовий коментар у відповідне поле під публікацією;
2.	Натискає кнопку "Відправити";
3.	Система отримує ідентифікатор гостя;
4.	Система записує коментар до бази даних;
5.	Система відображає коментар під публікацією;

![Коментування](http://www.plantuml.com/plantuml/svg/VLJDRjD04BxlKwnw0WcLSE7Gf55VfQMkG0erIiq5-K0TQ2yHaP159AJm8rvW4npi98xz2ZDln3VZW0XP-UJTsPblllc-ISvkelDXzFhbm0o2gyW-3yulWw4nlQlmEhBFma4uFErqElRcnPlWzCdJVk-YJpDobDE2t4dlyKNVqcUggAGbRJdXaSHfY_F4Kethd3RyYTRa-0xVrN4hyW--H-8jwWkK53lyAM9lQSafttA2KwKz96TbaLOXLEYJDkTx-u1gAQ1CekGGLK2hgJ-b5bJoXX9F7pwozBr1G4r9hftZLp1HSBGhbKlnHmSF5UaEN7sW_5_gxLs-eKCEb0sFPGHE3hKMLRppaxEK8I_39KLuZCU9XZoMyFIutUqlweSGRnG7s9qGaFRYg18p9hY-_BiyiK-AsEYccHE_KFWib7CXZArwiPOCRTrO_T_iF48LA6HKuqLFeBMqUjteGMA-eLF-q3L2PIRQ2XLzIj54Xwrf3VGZ-jZ0WwqJ5f9wXC9uVs5YXTeBoQubQdh98-0gZb97rhiT4zqBYusiL8f9ruUJetMj8U0SYj3OEjUVP24tNIz-xyLIZG0mru5-aVCYjgi66yDNNNC6m_6lyHi0)

[UML-код](https://github.com/nickname038/kpi-db-subgroup/blob/master/UML/user/Diagrams/comment.pu)

## Рейтингова оцінка закладу/місця
#### Учасники: Авторизований користувач, Система.
#### Передумови: Користувач авторизований.
#### Результат: Змінюється рейтинг закладу/місця.

1.	Користувач натискає на відповідну мітку рейтингу під публікацією;
2.	Система записує оцінку користувача до бази даних;
3.	Система перераховує рейтинг закладу/місця;
4.	Система відображає оновлений рейтинг під публікацією;

![Рейтингова оцінка закладу/місця](http://www.plantuml.com/plantuml/svg/bPJFpj905CNtynJp0COFDou--0Yl0bAY2L83TMDOG1jaGyG5mSJ4FyON693QKafvXNFVo7kPfjfO6rcGp9nXpk_USoVjJBpks7lzSgY6pi3JpvrktnahrHgu8qy_SuVk-A7HQEZ9YpVEmvEdxLQlZKymYB27kM_TzTeQNn7YI3vYdF43cPnePFIMjYmaiebWU762mO62EwIqfJcVhn_NShxJ4eRcR18ZGPpJtcFFh8nch4QM1ld7KIEnCdlx5CW1BHzfVBCAGgGmzSGl2DaWb2gHYdT1_VYtjQO5Yqk4lvkD9OLIkqMp2ElH4cB4rYTQiOaXFmT_G2hMz8usZ5wnrLhJxC_4w-AjHNwMRANBF3zR9cyCpPXvl5QWb3Fg5yzYUcFyKtLzNahTLqS8WVaY8k7LvYfeHcnnm0LPlZfJe25j-KXuMUwVXNycqEIIomzWAhMK9Nlz0f42sXJZ55PbLtBbW4nZ1uC8CUzi2hHeLjbVxBFYdw65D2MO_vvYfQND9SDEJF7JPfVbupmXj3EvXJ7nt5TDrU5fyyVW5m00)

[UML-код](https://github.com/nickname038/kpi-db-subgroup/blob/master/UML/user/Diagrams/rating.pu)

## Створення публікації
#### Учасники: Користувач(представник організації), Система.
#### Передумови: Представник організації авторизований.
#### Результат: Користувачам доступна нова публікація організації.

1.	Користувач натискає кнопку "Додати публікацію.";
2.	Система отримує запит та надсилає відповідну форму;
3.	Користувач заповнює поля (назва, фото, опису, інформації про заклад/місце) необхідними даними і натискає кнопку «Відправити»;
4.	Система перевіряє поля на заповненість та введені дані на достовірність;
5.	Система розміщує нову публікацію;

![Створення публікації](http://www.plantuml.com/plantuml/svg/ZLN1RX9H5Ds_hxYfcpOX53OkW99k_0TtPYg3RO9WODmO5Z2ZRKoQaZG44wDMuzBD58jC2pCa_OBt_iXpxmEKE8nDaxRpvjrppZttN3ZiU4xRU_soeHfktQDZrwcvRQKgzLRJe-UjHgjzK2WKg7FonZqeFgvMZghwimxrL8zrMAhi7rL9VpC-dXBJqnCTwzWCI2zCeA_rp8pqdGxDgHcP3_bCpE_c31Vxg8zG4YsHFmfgPFh61o0OpTaki9deXWyXP6nBI6x-n44CqkcAT2y7UHO0DNCTPgkuqfCbU83B2S1NIgvMfF-b9Bu1Eb6EOqO9fU8sc_mh2AOWdfbpxipusqq0u9pq3LxOmmNmGy8l8KkpVx15RRQaI-uJE1UWH1cX_KW8bzMYS2i2FNdwh50e4G8p8NZI1mAa9W2474YG1tPpmjApSOh06Lhrn1NhzXa2Mdhy9ZktNoHVbX7J85IV2dLeUl3ardQZt6PjlGRTDFUxIdP6bL9dGmBeyw6uFoJy0IsQlJC1xQ2B1DhbIjgaBl8xPV1kfBQhGBPvH63s9M9p4p29zHFZ8KwFg92yHdfcLS0by8hbybyCDUQjD028yjPcj_IvCK4aPFXdjhj2BXyHEKk1AUL8F62C8AS84k8L-tfrPBSJYupSSGVx43UoazgJmGFbshop7N3tx2BiN3qev2Dx0lS_zAMKWqosEUAxzpCuy23V5_P3mgRE3FvgN8Z_IRR8zysvidCPusS2TdcpbBxKd9ffMmnnpPRdKllanR57ZnodNdUSpRYttHh7dFGdbF-2Un6O4hk4-OVUBERj0Z1PIlCy7ZsLaRotiOj5Qv2QP8ZkUArNPNK8I7p5_0O0)

[UML-код](https://github.com/nickname038/kpi-db-subgroup/blob/master/UML/user/Diagrams/adding_post.pu)

## Редагування публікації
#### Учасники: Користувач(представник організації), Система.
#### Передумови: Представник організації авторизований, має розміщені в Системі публікації.
#### Результат: Публікація змінена.

1.	Користувач натискає кнопку "Змінити публікацію.";
2.	Система отримує запит та надсилає відповідну форму;
3.	Користувач змінює інформацію та відправляє;
4.	Система перевіряє дані;
5.	Система змінює публікацію;

![Редагування публікації](http://www.plantuml.com/plantuml/svg/bPHFRjDW4CNttob6NO64IjYmgDEeLscfAv12ZHApGLcuDcg5X99Db4X8410NC4wYE77YN67cHhpvR2DPE86kuendtk_D7_cYxr_s_FTlkwRhtlZqshsyTdl6j6-yMvzUULslTzvgjQZ_veDx_k9bfttLuQySyueJZi_QpwywnDzvoGl4vX9fb7Uyan7n7dz_SIOJtd0izpAHwUbHtP_oWCGxrASeIKlrBvnBmAdSILZeoyCJQ0SArI20IL52DdEk3W1TLT2dpuX_50AesN9ytCMCbwLuXEGSufMJMGNz9v8q0pZh765LYMt56cPWGSQ4LpbURP7_2RAe9qvgJX5v_11r6IiKPV9PPoDXPVuleH4LUFW2NiToLFYRtKnUThuckBml2YM0oDfoZ75lh_ySqQ1fUGDZBywSDQwMh62eGMjqJFXHx9ut4j49JqlBgIOrpMTuUkA0NDlum01N3-dcGgL3Br8CbWS8P4ddPdtONQUS5JuIG1P8oSkd7Vp8Hzi299o3xHxij9o-3A6k3vLOrOWrOYgk1FRiCXd96B3_Qd5VtZ8a9D25BufBTHgIQtQQvegYlk-zSym5TemFncy0)

[UML-код](https://github.com/nickname038/kpi-db-subgroup/blob/master/UML/user/Diagrams/change_post.pu)