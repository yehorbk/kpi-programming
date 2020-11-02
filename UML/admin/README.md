# Адміністратор

## Блокування користувачів

**Передумови**. Адміністратор слідкує за порушеннями користувачів.

**Результат**. Можливість адміністратора блокувати користувача за порушення правил користування Системи.

1.	Користувач натискає спеціальну кнопку "Поскаржитись на користувача".
2.	Користувач заповнює поля «Тип порушення» та «Опис скарги», після чого натискає кнопку «Відправити».
3.  Показується успішне відправлення (або помилка через те, що не всі поля заповнені).
4.	Адміністратор отримує повідомлення зі скаргою та оброблює його.
5.	Якщо на даного користувача вже приходили скарги, то адміністратор має право заблокувати цього користувача.
6.	Адміністратор натискає кнопку «Заблокувати користувача».

![UC1](http://www.plantuml.com/plantuml/png/VPNFRX9H5CRtynGtTTCcjTADCIqbDUh2dHiJTsPQXfP8mS2uCIpuaxHTaA8DWSHO_DEbcm6XZ1qO4fxWt3VoE_SYTjAPkvnxpltExvppNTYlk7RP_N1Ii0fEpXN7ZfrrobOwLogwuh1KA9NtKgcKgEG_EdlRJpBfWymh-_2TVUJif1yTPCJJx4c-Q2MaF-Rqbyzrvkjd3xTDUNH57areI9xEfy_udWcwfL3Mo9TrsP1D3iipsQMXKUfQdY6lJZFoSTzV2dwvhxGfw1EDQ0h5cUogI0td3Sv4x8VEfZ5DoTiobln6OrmTqmZIKmeXhyiQ2WWG1WYCw5OsPKUWUq_Gd4FuFeVO39VQaFCJns26-WwD2T83sK99b5qYVGNW3GMOpd09rHBa9N4orO2NWVAD11Roal1nn18y40fYxkgiwAnzSrkNQgs1l41TqF8SVPO3o2dWUwhBH0NnuitRL6f7K8y6QFUFe24lOOK9muXrK8qvK8SyzuHgRTMX-XXoc4jl63dxoe8wtKSXg9toFN3MkBBcj9nYzj-piwfnBgrQwerQO8w92YNOu4EmUxA3Eg0Syop8uzs3jCcJPvOvcqsimQ-XpeVSZLuiH5jAB673QxjM0a9aCbXBv__C5h_e9vgVnpXZ4GXs9QVq4OMYM27z9dyHRE8Icr49WI34SNYltMXd4BkCh1EjiTQMXhyotLsBkyfTLwE_15LMmW1PWoRyTla58GxA9WzVdaD7EoWY6AmUnJg-1nJgES7m245i0xMA9TSHvVpHiIiUs7OkPziHZvMTBBmLVSCKQazlAIkn092JVtSKVb-T-CW0liRGhC2vmudskdUt4igBPLC99j5ZxjC0eP06_4gD-bYctcWR2epQO1l6k4KBNmlkGr7nWA4suWNgGwwXJH9pt_1332cpBNfgMm5ld3lLoOPNKd5BxtUjVMm3_wj_0G00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/admin/Diagrams/UC1.pu)

## Видалення публікацій та коментарів
#### Адміністратор має право видаляти публікаціїї та коментарі, якщо вони порушують правила користування Системою.

**Передумови**. Адміністратор має право видаляти публікації/коментарі.

**Результат**. Публікацію/коментар видалено.

1.	Адміністратор отримує від Служби Підтримки у спеціальному розділі запити на видалення публікацій, що порушують правила користування Системою у вигляді посилання на публікацію/коментар.
2.	Адміністратор переходить до публікації/коментаря та перевіряє чи дійсно публікація/коментар порушує правила користування Системою.
3.	У разі якщо публікація/коментар дійсно порушує правила користування Системою Адміністратор натискує спеціальну кнопку «Видалити публікацію/коментар».
4.	Система отримує запит на видалення публікації/коментаря та видаляє його.
5.	Публікацію/коментар видалено.

![UC2](http://www.plantuml.com/plantuml/png/hLNBRXD14BpFLym7X3mk2EKH1S656nS-m8at4E7Oo3ONv8CV8X0fiX6Ap0a2of7BuWTUFpoMyWNTVqIL9p6ix6oiY4EKtTxgxkhgcl5UePZA5zyUPqmcE2pQLq4g7UJDzc4kMxG7kKmklxE-lcuBH--2dOr7kzlxkyzJ1wzJBuFDxRNzNViuVNoKDRV07nB-xAb7ldZoO2C99rybb9wq9FHu-IvTwI3MrXgZCfQnDgnCyFfBXjgKWOHwWlzzgrK9BTwTZ90qvgkMyQMLsF1IFm1NGU48kT5rsqzeEaBkM9jQqQgMWQcAq_AAbHyICOOU8mbN4ujVI1Ufc41h03jftTt0iggUSqJ4aE4iqoW2vcq052qONx-ipK-Up8tAzb1dg6VJXEeriukvslMvslzGOb3SgadizOq2StxAp5LLz8I9dgVqfwsD2RBf6-kPqkqIbSpKhMOpKKR7LudmkKOvMq1rkBmXvlkD2IEEYjWDZDktMWCtcKYNWqj8SKYSHInWJdf8Q58TYySGoCXl1AF4H4amwehLKt7uH9uWzn5_TR0u-xlpI8RUoq1ujyNi7xEWqpfe--PjMeGCVVKA2ysoFCV94klTCdTeE_6-rlVY08ey-Owu9PtPi7oObU5k6CMQS1WZLA9CjCpYYesvYd4np-yjf1_yqZ9RUf0HQWxqT5aQCUR_YrFY8iPy95u6RBB0lBJ6W7naGeoz-YcVPpRrvbtA4rT3Y5EANtubg1MFp1sxsI5P_eWaMIPs5Q9y7x2sEExjdZSNKWl5t9ijiuVR1p-0Vm00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/admin/Diagrams/UC2.pu)


## Верифікація облікових записів представкників закладів.
#### Адміністратор має право підтвердити обліковий запис представника закладу

**Передумови**. Представник закладу створює запит на підтвердження статусу його облікового запису як облікового запису представника закладу

**Результат**. Представник закладу може створювати публікації про заклад та відповідати на коментарі

1.	Адміністратор отримує у спеціальному розділі запити представників закладів для підтвердження їх облікового запису 
2.	Перевіряє дані і підтверджує обліковий запис як обліковий запис представника відповідного закладу
3.	Натискає відповідну кнопку «Підтвердити обліковий запис» 
4.	Система отримує запит на зміну статусу відповідного облікового запису
5.	Система змінює статус облікового запису
6.	Представник закладу може створювати публікації та відповідати на коментарі від імені закладу

![UC3](http://www.plantuml.com/plantuml/png/SYWkIImgAStDuSf9JIjHo4XDJ4ajuh99oyyhKKZEpyaliZKmC50epgnAjJMqiBD9iWj8JCvEJ4-rij5FibDmJCdD1DHMDRbD0s5qxrFC0Q0R91PaWmGR3i0DO5iuG1PDJTiD8WWXLq8g0R5aCnYRE4xYIZt1cnlntioWOBkP019I5lOttpVlnsycnzcUzljgV_8uT3vzTFTUgWzNi5YYX0tzU8VQdQ1nhro15jQTkyBD3JfymzgNEfHSFZESihZcuupbqk2QOpKglfvoeMJd5WtQiAZU5cjOL2eS9IbzSHS4deLvD97OMrJOS7Zh2c4GpHAfSoTt33wZyRWrDh1y_w1wgBbSujn56dA1EjBFiGaI8-nY8CkJwWlAZLyj1UhUkFSxQquD-wsyAL2fnSDK-86Q2riQ6_OLJJxb1Yk2VqStD3mMTvOJSuxsS1knRnC0Ev2GjkSJQYnTJgJNWUxVc2D3fRZd4afjWqRySgzX5xVBGBhhRMG4OL3AIOhhubFSH2vx3pPoLgq4AOwofAgFFcDTvBqIltEDXs6ilCWiUtxyxDVvpARxOpZD_97E7YIYQj3vruRBEOFYeqCrjNJ3obynqggH0rZglCYStpA5PlHH4qVDeEByF9d1ItTsE4aJAOldHERJepabw1j8gE5lZ26LmwrbzMvZd-DqIoB3mpXiHNoGd4ZzAcJ5pJH9LkDPPRNL5YosVBdvYiL0aBS_pVPcFSaObFwTD2M3VcKOXT6TiOmHoWTtH4BquKyuPX5XT6_rWFvaDwgyvQQbrlztC_p3BH3R6T1OBqRnuD5zyNAIFUHHvr_oJm00)

[UML код](https://github.com/kpi-db-subgroup/kpi-db-subgroup/blob/master/UML/admin/Diagrams/UC3.pu)
