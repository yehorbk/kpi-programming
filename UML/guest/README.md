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

![UC1](http://www.plantuml.com/plantuml/png/fLJ1RX9H5Ds_htWVO95sOKoXf8acnfqRFu2sGzk87GFJZM4n1KKNn2PgkZ2sM5cuS3CTPjfXW27f5vptHvxRHoMKY8jkU6_ophttd7jEsAnxvPft-Bgggax5qtjEUSUfgMB5FV3qjbjrQnlvV5xNzzyw6wkFIyMjqelozglohhDUVBXLqiyEdRgd_W5_9F3dJotovPELrMKud2B05K845eykClFHj91gJ7XSO6XEa28mRPw3fQrwvWDnHnWZOKKoRVZ5d9WZqpIT1nhdIEIE62C4Itjr4HkVkCYqYCqGBlRJvZqoZemr1OmfOy3EYIRDiNc7ZEKZIzjy4Yq-CW89Ip7aRwI93ZH2uYFqHJ6IfPH-8COLSKFJaLBJN224Z8UF12FJCb_lnsGfbJFPCcGhikk1vlmsObc2ySMc6sPAEGSxjybIZHdFXhe9drhNE1KTOefOJCeyfEy4gMdfwz-pD5mF2qeAFYFaUuH46baL4_dWAqVC-TiG_DdSHcPuXY73XQm24h5ZUHpmeuziRXqM5E0IGe_NEnuWuKOjIU5Sc1UwoE3_7QIcUpVvvlXlo13PJLD1V-QyPFGIyTHUz4KJaRQ_X82NgJ96DfcDJeaUIKVJjEuLw8xxXa9g-xjxdgwuhYV-uHTYGaB--WALIJOlFibE4EGqlYCJTgBD4ecdiOZi01Q4Yfx_H0yzZM_eeYqf7UNGpk5Sv4fQgQc3r9gXY4gaRcKjlvQNHDqoskIT_rz_0000)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC1.pu)

## Реєстрація користувача
#### Користувач, що знаходиться у гостьовому режимі має змогу створити обліковий запис користувача

**Передумови**. Гість хоче створити обліковий запис користувача.

**Результат**. Гість створює обліковий запис користувача.

1. Гість натискає на кнопку "Обліковий запис" у головному меню
1. Гість натискає на кнопку "Реєстрація"
1. Гість обирає тип облікового запису "Користувач"
1. Гість заповнює ФІО та поштову адресу
1. Система перевіряє введені дані
1. Система надсилає лист із кодом підтвердження на вказану поштову адресу
1. Гість отримує код та вводить його у поле для коду
1. Гість заповнює інформацію про себе: біографія, рік народження, адреса, фото та пароль
1. Система записує дані до бази
1. Гість отримує можливості користувача

![UC2](http://www.plantuml.com/plantuml/png/hLPDJnDH5DtFhtZ1BM0jYJ4K28aQuywDYJipm1I8I4qf6yC2A5GNJPieAOaH435nEvGE332T_eNx_f7dl7dOLkZWXxith_UUU-uvzxvqUgNa5akhhvUS9IzVKWkUE-SLdObyORcaPWjBXU9a9fDHAujllSbx3wOcPgQUkRElt7blVEBkp9Hwikgjb9m1uVSP_lHH4ldyuKWsBKxsn9SpQOgVnCiN2VIEtj2RUbryNT4DNLTo8J4-GtDTPh1-9tugx14Zz8Qq9KHsQC4_0euOrM4bXmcU11BTWdK0Ikk8Qw5s9B4qh-CflIqnIWRAO3OJlZY52Wd7SgaRR8AfSgxGi2yTrl-BrgYGd27sKbTHmDURryXqEUYQtld_33vGL23M4DdM3TIJaCdMi5r3Q222UlpYPIOphkJJzSA0KcoAdab4zLhuQDiFn9nIOlI9kcMqfjAhP57bG7nKYIc00bB0teyXnWdkQvGBzUlfC6E0sP7O4ksGLApac9FRGr5lWo20MuWhemae8-UfIoBxRCIOqgOjDAu2TzkapEn4ICTRdhlQK6Ujw_EQOvRO0RizpW6bX70-BGS4dILuHovqMGt9VieK32c4o0bbidHYYNWLaOwkvNwpo4thEyHaKpt49HE98frVvp9c_HvEnBjfHXAyNOObN9CX_oOLsJV3e_Y3VeyZVWOA8bjSO4Bcg63VwgyHpQuu_OFoTU8rfScTD_qtZCayv9pbGibJvj6yuxhvlElsELpqvkYiaiyeVWerGtQMZBpnaUbMJ4wAX8YX9WmbAGKzpfIHf4KJq8oPAIuqERQ02ahWKhS6D6a7PUDEfFVUFprqXKPnkxXDjghLaFsJGyXW9UVM7ri2T0EASaaQ9etuDncZ6pXi6HiZEn8rG70d-N04c840QLX9LZ0JiiMn6LPc1ovCbupkRNsufp7n4Oe2xFdA_vyxNnrW-6vtojYuTRT_i__1wspNQuDHN9nV-6EGiIx8RSP5lSach37WOS_XqIYyWIe9fNm1y7XMvBi4LpDcDUJOqH3aGizHmv3xG5KJ0mFxMfabOKrfEXZiht8aHtpU3wH2-wDHgOpA8Kw64VXKUU8uEOWAcJUIpMIJ1R6Cfd76tvCV)

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
1. Адміністратор отримує запит

![UC3](http://www.plantuml.com/plantuml/png/SYWkIImgAStDuSf9JIjHo4XDJ4ajuh99oyyhKKZEpyaliZKmC50epgnAjJMqiBD9iWj8JCvEJ4-rij5FibDmBqqjBk72eTmCfDpJ1Q8o551h5UoqhGNHVRxYYhSD208hs3pfwVr3TrKaeEq6AigI1ObBqaMKL6qKfAgGKYfrQun37E8ult3k7tNElKFTD8c5KBj0iczcpZrpvioO_rOtY-9mWH13H0XzFBvWOBksPkls5A5js9xj64pbPO2OnmWbU884zmWBWQzjKm1g6fie_4S197YhR725XC-2d2AKz_U8aTeU9enH0dLazhJmdZu6oYuGd0pH_5t6dWbC4mF3TqJ4H29FYP646upbqdkVYf4HEK9CoUr9XLD136qWg2rcsVeSdPo5RTlkt-3mmSMC1Rv9EUL6rci3RUcvexGKmVp_xFdw-hR19rMgnboQn3O5of08UugK2iRoCj4NYRcZp3qstWQsMtp7Xhy3iS4D5KD6X8Zboj-4hnDve08XbQ6cxjWKurO4juzGqZ8Awr2ewOs8V2ldRRP1gkeKmsmAJ1UPbZzbgPamTHEJ5sxFXBG0iqE1hLDlZ8g1jxOBtAve_97mY78tr0jd7fTK7PbwP4IVDQWZbI0ft_NIti7kmy8fdUIsF2cvdLGIRXVamhxJQE9GGXXv9lWKzpOmAxWiCEsAaH3SKdsbao7bKKewjhtps4iMRACL9hlR4pba8b4m_NsCCjx_2oU7rryqInxnd86UhP_ARsZWqZ3Gy0VxZkr1n392n0GYw4w98iwiiXEjZlVGixwwiGynGd1e7CUOgWWsk-qM0XTPZ3jg92GwgaX4VLW79wgOoi7XyPvn7vH_gjNz_MfrnYv7UxkqYS5dIRuZ8ShaXzsPWkcpbd1IKttED-TPcQiid5NMaJ3OOAIYAqsCENMnzAIZQUIuI6it1czfVgJQvxPRVDf1xZ9Mkar9z7jLDlmPGp8HGGAUUTtA93REFpvbDxXqbFgFYvzfSuju-dDdj9RrzJpt4pDYrvRUp6fGS1rZNLvKGHBoKTQKSDaQGAZzF7hrucNUqCTsj99tzCcksFW369ippbgwz1OuBPTgNeZ7tx-Lt__c-F2rjDN3x1_AaIn0VCVWOVXqrbtRRkKre27MF6gC0MsXdsFTgx6taoH49LpWAwvnpIzQ7mrwEbr3OmrNVYK9Niss-CGPAKbKmhpLodh5Jvyo-bUUvV_27m00)

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

![UC4](http://www.plantuml.com/plantuml/svg/ZLN1JXDH5DtFLxpWLd1eZ34K28aQuywDYJipm1I8I4qPDeO5jB6w842K38aH45cuVGoj7KgP_i9zV-GvRnuX5JhfecJcpRtdddlElO-vzIYeHHiVLhtLi1AfvJ1O36lUTAMw5gc5wcgrDkFxlbfV-HJEJ3wTdPwVVHqil0-MmgdfH_EpwkL6k1vvGyAVCFpLyppopRFnnqLnSYHQEfA8pkDbNn9JbyniIOfpRPecDdjAklcHsJPrqs2u-I9Q8L8hwUDBMrhy9XhVhf7QvOSE_xGaapv-FVmkWBAh-6g-8ZWjP7R64cRRmQMEttVm8OcTXqfESqBI1hWkn3gHjYFPi4IIktYA8EP0MSH4CiRRsfSA2UToPMBfCfL7jZVfi_umRKGZAHkcJZ7TNyZec0PgxZ3Br7Eo0sprW57afHrTqnYGniI5jRwH3ohjWlMrYT6_f6p4UNzeImz5K2_UllFzAIK_xee0A3iXT0_YffW5SdGlU6WhjeEg3NDGN64I5Gv4Mu9oJcKeRI89fRK-PHRGggtf4RNZSJ5koU9cZdNVJYiAs9suvMi-evQ9QIAerib2BWlNJuxP5rrndY2pQNbgiyNiN5KlN5kysNrlyzRTJSzU3nxO7T5-wYfTEvw4uCWHl2zTU3qcnmNZESPnuEB9bQE3LUHHZtJCRdd48lTV36Cs_P35Y4v0fhi5vn5BQMbn2QZUpPL17IIZIMKFhG-kyYP1tSfIU4Ys1rY0rctvtiqajDm3Uk_yDrs9iz74PM-j6eMgjhAq7Aa7GL2f1C60TxLmaPuf-Gb6Vw5JoltF9tlKmCbH0qlMSp8QT9mjxu--qihiIVVUgwVuuYbZigeVeNakHwKA8fWz-IDjNdlKt3d4UPSBl3RereJjXRj6pnou6scxW20GI-9Xb7xBcPpnGZYH9ftfJKXpGaxnPDc2pmwVE9CUebBcZPVyac-LSOpcy8p_Zly0)

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

![UC5](http://www.plantuml.com/plantuml/svg/fLLDJnDH5DtFhtZ1hU10eZ7b8oH-47TkJDoP0QP0g8nfXutf0agiBaWnIafY14GMRiUXjGDjwL-uxnzvpdibTRGp8N7Hv7sST--vvvuxNQo4NZdSVbroIdunLEk-j-gNdRbYi1MgbQ0KbETTrrMLZRV-_FJ3XRdbXUVUogQtvXVcxYqlgALjln8w6V07X3zxR94l7atUpyF9iKJIaLWYYvUF4kkQNEiTIN0UwRfkwWCbL_P8x-gQtYDSlvT84Q6a9TSomA-7tmLm3ON5J-dg9fz9R8yD63Z6s5DBGR1MyXMY9Egfj-8l1y5cBizp9jIxqfS4KPCXsyzWHqhxTvMSMNhI1f4eDzQfj55CMreeXQJZV-Cf1j67YZjMOF3CVVbtSJmQbNPJc4G0NT-kj6y8tG6Lhjv7iaZNB9aKcoZL5kQDXdJqNgfqtSpDzOdo8LC3SlPr4_L9ObfgEtraKcT6K4zUldBTGaQHt8yrJuSNr5n_m4MNVKHDKB2Zh77CAItMo4yzNL1o29XruS1OJu43BPnWPqNHxvJ4YDwYqtIDTSfbxhJ82Pr5MQseR7lTD3m2QRosiZZ-rkhDg3hLKNkgZfbc1-oEsJzs0-NGFmoXi6RmWLoXMHDoakEV2VQJuo9TIuVoyAX7EhenUyiau-TumZnd_WGNV3gsPOsimSveFAEc4qBtGoe3VGuiFQnuIpNxJ38-yr5c1gUQ7l0gSnxToCPym_xhPjeMiyvM4FgglB6s7gexdbSiUbxA2sL_bHvGyXLb_eBk2GVU-irqdE__8uWx2f8sJG5esuJUdu_CTJFhavjI0SLLmk0DrB7CYa4GqfloGzg0s9chyTM0yo0Ns69k99goH5lIvbU7rpl0Milpi4yA4ZkmsdSvbtCbN-HKwfpPtfJKf-GCAqEGeymL3U80bV3Tv8mxOyiUCbh46dzslm40)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/guest/Diagrams/UC5.pu)
