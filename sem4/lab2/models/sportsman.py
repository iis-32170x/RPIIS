from pydantic import BaseModel, field_validator

class Sportsman(BaseModel):
    """
    :name: ФИО спортсмена
    :status: Состав (основной/запасной/n/a)
    :position: Позиция (зависит от вида спорта)
    :title_count: Количество титулов (int)
    :sport_type: Вид спорта
    :rank: Спортивный разряд (1-й юношеский/2-й разряд/3-й разряд/кмс/мастер спорта)
    """

    name: str
    status: str
    position: str
    title_count: int
    sport_type: str
    rank: str

    @field_validator('name', 'status', 'position', 'sport_type', 'rank')
    def check_is_empty(cls, value):
        if value == '' or value == ' ':
            raise ValueError('Field cannot be empty')
        return value
