import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SimpleDisplayComponent } from './simple-display.component';

describe('SimpleDisplayComponent', () => {
  let component: SimpleDisplayComponent;
  let fixture: ComponentFixture<SimpleDisplayComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SimpleDisplayComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(SimpleDisplayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
