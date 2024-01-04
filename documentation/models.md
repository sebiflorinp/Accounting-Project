## User

| Data name | Data type |
|:---------:|:---------:|
|    ID     |    Int    |
| Username  |  String   |
| Password  |  String   |

## Transaction

|       Data name       | Data type |
|:---------------------:|:---------:|
|          ID           |    Int    |
|        User Id        |    Int    |
|         Type          |    Int    |
|         Value         |    Int    |
| ReceiverId (Optional) |    Int    |
|          Day          |    Int    |
|         Month         |    Int    |
|         Year          |    Int    |

## Important User

|           Data name           | Data type |
|:-----------------------------:|:---------:|
|              ID               |    Int    |
| User Id To Which Is Important |    Int    |
|  User Id Which Is Important   |    Int    |
|          Description          |  String   |

## Activity

| Data name | Data type |
|:---------:|:---------:|
|    ID     |    Int    |
| Activity  |  String   |

## Account

| Data name | Data type |
|:---------:|:---------:|
|    ID     |    Int    |
| Owner ID  |    Int    |
|   Name    |  String   |
|   Type    |  String   |
|  Balance  |   Float   |