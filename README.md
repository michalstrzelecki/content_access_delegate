Content Access Delegate Module
-------------------------------
Created by Michał Strzelecki, @MStrzelecki_, m_strzelecki@interia.pl

Installation
-------------
Simply enable this module and module dependencies.
Module dependencie:
- Views
- VBO
- Content Access

Bonus
-----
As a bonus of using this module you have Content Access module and Views module integration, since interface is built via Views module. You can built that shows witch roles can view a node (based on content_access table). 

Usage
------
Delegates Content Access grants to choosen role. Navigate to www.yoursitedotcom/admin/content-access-delegate, interface is built on Views module and you can customize it to filter apropriate nodes. 

Rules:
- delegate node access grants action enabled in VBO actions
- view, update, delete grants fields enabled in fields section
- view, update, delete grants fields filter criteria enabled and exposed to user in filter criteria section
- role field filter criteria enabled and exposed to user in filter criteria section

Permissions user must have to perform this action:
- view published content
- grant content access
- grant own content access

Todos
-----
- add filter criteria to filter by view_own, update_own and delete_own grants. It gelegats this grants always, as it is for now
- add fields that show users whith the abilitity to view_own, update, update_own, delete, delete_own nodes
