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

![Редагування облікового запису](http://www.plantuml.com/plantuml/svg/ZLLTInj157rsViL0NuL6Yo9-YDIsq9VIbqBVocesCHYpabqfj2aOuqSVH45iXDBQbjAdlgpHc3Mh6_0NtFb7FNTcxMgQNQl8ZhFtddlkkMTcvrpFgdfhAsLHjWkUNBAjl5qLqmMduib5f-nKPtAvd7HBx-oPaOdPwONPbzRYibMq9wSVBipALsvgy3W7FtyInyq_oWgZh-HJXrhact3wJcqwmzwfQl0kNT6LsfSKqGc5gabTh5huEwL88i-d7WMghXgPDNwg7V9L7LW108AuqcUArBhEtZ2rrCwmf1zc1omkoSz4_KPjv8CjiY-PLXQo17-Vph4yb2OhwH7L0aazR4Tg4ps6QZUpC4lKGIhYa8hqkEmXowMQCPIaxhyqo6SfhpJR431OPPOwq8g5QW-f30qH0utcgstLL4UwSYh2qzTlShb9YHctOp9uWZBFuI8PtqOcmCWaTnR5NVGab8kCcXt8fdK4djgIr89sPsm6Be7rHIRkw41Y4M3mo_DfCuWfW4McJCUgRaIDMmE9RQskhzQPY979hkHlJfbmbqkLLQjghGovIrRUULkg56N1AhjsyaQ-S3nRlXT3Zt7kYbLdhPAVv-hoGM5YR7niGWmz0wERBVqZFWXH6sI_cj27NQ3dsBPg2tpFz3HtqNF_2RipeFgK45ejRLNqsjK-neERxa6wXhp-tNzqEVOwH6hjxg6gnLWyAzG9DLPYXh_sZOLFzV5j7qo92ejLBHMNF45VmEeSm0624VE9Vi67MdwEkZTq90aTH5LjQZwNQ9ewO0k4KEsZis1OujbDeImHmRNQ4bW-_wFVmXt6TXqWDj7mNd8bdF11vpSjdXd2skOwDBq39WJuESBu-j3ct-2gmEv2abGheAS3h9Fn6-_UCllWUMF4Hyn97vVJpF4U6qXzSnmciFTAFve-fOo1PdLwVAE9QZ2JdkcK1GJPC57Kc0v1TPPIVMIr--_A__eIGH7NSrQdn1puuUlw1m00)

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

![Пошук публікацій](http://www.plantuml.com/plantuml/svg/XLJTIzjG57_s_XKNzYeimXJnGsHkWxsClGpsDg9DQx4caaG6MmVQMBk1J92kWx7fnjXxrCQczgF_mhd_qNxd9gLKshGlkSazlu_pSRhf-QRh7-wNHCdA-tBNCdEMAzRoZktB7QVakEk6OKYl-C5QNrZUMDlUU6tkx9a5QsNjyVQ6VEDD3LxYu9VFqhYj9rbXz8j2Qj4DXKauNL5VVLO1tKiQu75D7TMWUmhLAPxjJAg_geQuO-fH34IS4lu0uH75wbXLm0SXLPkNz2VvGX5rASnalQ88-8YQG7Uf3uOCPWd38TtXM8V_57cB7CwffmBenHFIKjyp3Vm6HKi5G9of2X2LBFa-Nl2Hkb23XIRrq_k1Vf5GxQaJZUmErUUb-e8hQYExMpwq-2Rnn-bIPqQ9BhZWyFTLrS3UaEX1pA930MruAiFpj-yCOqLY4YAmm1a_aIctiQtDq83vCWaMG51_c2mt0_YOtqBcKrL9DqYiYRY09MREr2NF4tSzjGFWAVpraDeHWvFKB3itt1_XxHNj0zCrz-UyNJFdl2_Q1PatIvurkf6l7D-I7yNSKsnKmNKExTmMgyj7-UN5fSLbCVS2ZeQVz4zy4g8ygULbeTTO8FzqKbKLVfkw0sUIdKhkAdMIB5GW6Sv4F0keTB0g67s1sn5kL7O914vC4E6GhYTWypg85IBSNgig5vPwQHCQMff71_4LrjOJgKuGfIUP4u5oUNmLospb4cn7pCap1T38pAgmkNHkiR3h2_g9c3j8n6nTqZVwXq7GpU2ecQ76A3Gf7qno2VMMrISjQhegwH1nCT9J29_ZPKDPftQCKnpRquST0Sya-NFgSitGSUTWLMp2FVwz_mC0)

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

![Збереження публікацій](http://www.plantuml.com/plantuml/svg/XLHDQnDH55td_Oe7RWMdYvJGfA5O5To86y6TJ9l91qrdoimKGIEq6MmtKa5g0gAj8gxSZ34nqqm-eB_Wtd_aUMyIIffaMXYcx-NSSyyzzzxPydpJzG_tww9kbNrPjSoIvOf2sR5zkUlK7NVJC0pfrTvOcskvOc6d-DpStJChraRXmKvHll1MWjSL-EcZAMuxcmQZRnHIdpeK9d1gqn_gyH7rw1-U4OtuOshyJpwba8-1Z6X0qPJb2ut14V4nDpbGx7nwNzAFv0QyGmfJMI-d6heS03kcJXgpXEGGSaC-bwXbflylCaKIa0a8kdWKQiI1f0a7ECJSeW62JhZ5PwbgleEjZvYOFu0pvEPKo-KYZzIPkYeJZVL1mfo94am3bRj_oz-8tqk4BnHrXq6VjDqndm4vufPA4kdWH4TRArp9yFZbAyFOa6X-BycjtjpKJRnI6aCjkPbAi0Q2SmGdeYT9iSfan4Vg5CxAwy2XBd21Ie7_hr9Bkz3Jf7gUo47WYROgv2CLd9HcsQNPoWXlhsOVcAwvd_6gPibvNRChicpMFUlc5_dCyItvLcGUOeaghdDebxPLTdcldCkkPtCYymIAPbVwJxmJeh5itXf2RwxG1c8QakOcupVGqYUwrzU_gJq_ZTTnNe1qVX4QYkWYALbr53GI8MFOs4MziUQPdnfkBHlYjgAtLPrkhLBr1NsbCV0nHI16QpxJBtHDEwTGTqAD6-XA9vHqd75FGmuWNM-RRZZUGufd7n4b64L91Ah9mFtYBW2sjAwyWEFEGLviGH0-cFy1)

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

![Бронювання](http://www.plantuml.com/plantuml/svg/dLNDIXjH55vxd-92jq8JGH6Z8hKjT5EwANHNHZE9mPYHp4YXjQ0DrOqOAbQXL6qfNNMJZ1apvcS2Fi6vRzJlp9sOf6QcjGh9SEUSx-Uxv-YIxHXbPskZA8fcpf5hff4ros8-PvKSkMeLhV92AfMITk6jkP2UNPnVMNnXhAuRUNDk_k7AednfnnRFSF6pnr7TyanI6PrHZPhaKasNqoUrGm5rrI6VKHTFrSJ-7sgVQceNbJwro8zGlb0075_jgW-gmaXgVrBITtr27dMebeXwGHxwFMgWkmCzRXAof3gaNk7nM58JZ_LX3-3poPVKG-CkjT5qgIg9vDz0t4HTMnsW6G0HzSKmmYZJ0JvrNa4Yz16d18X3jO-k4maydus0PK-TgDEGAHRXoQlNgTISf3C8R74E_0s9dFsr5jHZl4I0D02EqQm3x4bgKA0JR79C3NO1a8-IN7L23THLc0BFrucuKsE50Th5hmTSZq4q0HuIOphdWU988siGiSVzY6c7XUYOp5AslpN2NY-KDesoiJ5XhnbPwqsXb9SvesYRWpVokUMOyfsOU8GzofUjhL9scTdbWzpizCpqh9Xu2aNze_17l1TYUzp8ROjmUGLxrYC6nIqzWQrGUWy1LEJDBpeTDv0txOm0zEX6R3FSEKX0HXt4VdoR5iQN8VwOuacfgY4D9yC8TCaIW700r6hCCa3XNKCPKU9qoeNycYFeApgkg0qPBfD-ffyOl31lhlfhQNfGofRwomoHR0EVBXnKOM-S4gf9hfHyXhTytrqsYOD1MEoYVlSlLIRskY3ZY1KYK9_p6TeMNJGod9cOkuauwrh-S3c_rIFBstsFcnjruVxdvQJ__NAc1gNH-FAIewIjnnSwzURZkuD3JqTxwyDbPtn-lniOCzizPa70Biy7KAy6N7sI01CTn17PZhMP4KkmWt-Ylm40)

[UML-діаграма](https://github.com/eve-va/kpi-db-subgroup/blob/master/UML/user/Diagrams/booking.pu)

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
