Игра "Пещера с драконом".

Пользователю изначально дается возможность выбрать один из классов: IronFighter и Scout. Каждый класс имеет показатели Attack, Defense, Skills эти показатели зависят от предметов которые есть у них и от их количества. Предметы для каждого класса уникальны. На каждом ходу у игрока есть выбор из трех дверей, за каждой из которых может быть tresure, dragon, free way, artefact. Условия победы - найти tresure.

Архитектура.

Так как у нас 2 класса, являющиеся однотипными (Attack, Defense, Skill), но каждое поле наших классов является индивидуальным для данного класса, то разумнее приметь здесь паттерн проектирования AbstractFabric(). Мы делаем две конкретных фабрики IronEquipment и LeatherEquipment. Они наследуются от абстрактной фабрики Equipment. Эти фабрики создают предметы для классов. Класс Person хранит вектора указателей этих предметов. Когда игрок находит предмет одежды (artefact), массив этих предметов увеличвается на один, соответствующая фабрика создает данный предмет, а характеристики пересчитываются. Класс Human создает элемент класса Person на основе конкретной фабрики, которую мы задаем в начале игры. То, что окажется за дверью, все взаимодействия, не зависящие от действий игрока, осуществляются на основе rand().
