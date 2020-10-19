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
#### Передумови: Предсавник організації авторизований.
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
#### Передумови: Предсавник організації авторизований, має розміщені в Системі публікації.
#### Результат: Публікація змінена.

1.	Користувач натискає кнопку "Змінити публікацію.";
2.	Система отримує запит та надсилає відповідну форму;
3.	Користувач змінює інформацію та відправляє;
4.	Система перевіряє дані;
5.	Система змінює публікацію;

![Редагування публікації](http://www.plantuml.com/plantuml/svg/bPHFRjDW4CNttob6NO64IjYmgDEeLscfAv12ZHApGLcuDcg5X99Db4X8410NC4wYE77YN67cHhpvR2DPE86kuendtk_D7_cYxr_s_FTlkwRhtlZqshsyTdl6j6-yMvzUULslTzvgjQZ_veDx_k9bfttLuQySyueJZi_QpwywnDzvoGl4vX9fb7Uyan7n7dz_SIOJtd0izpAHwUbHtP_oWCGxrASeIKlrBvnBmAdSILZeoyCJQ0SArI20IL52DdEk3W1TLT2dpuX_50AesN9ytCMCbwLuXEGSufMJMGNz9v8q0pZh765LYMt56cPWGSQ4LpbURP7_2RAe9qvgJX5v_11r6IiKPV9PPoDXPVuleH4LUFW2NiToLFYRtKnUThuckBml2YM0oDfoZ75lh_ySqQ1fUGDZBywSDQwMh62eGMjqJFXHx9ut4j49JqlBgIOrpMTuUkA0NDlum01N3-dcGgL3Br8CbWS8P4ddPdtONQUS5JuIG1P8oSkd7Vp8Hzi299o3xHxij9o-3A6k3vLOrOWrOYgk1FRiCXd96B3_Qd5VtZ8a9D25BufBTHgIQtQQvegYlk-zSym5TemFncy0)

[UML-код](https://github.com/nickname038/kpi-db-subgroup/blob/master/UML/user/Diagrams/change_post.pu)
